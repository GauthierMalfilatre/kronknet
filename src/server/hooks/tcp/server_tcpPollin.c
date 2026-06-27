/*
** FREE PROJECT, 2026
** KRONKNET
** File description:
** Server tcp pollin hook
*/
#include <asm-generic/errno-base.h>
#include <errno.h>
#include <stddef.h>
#include <sys/poll.h>
#include "kronknet/macros/errdef.h"
#include "../../server.h"
#include "../../../connection/connection.h"
#include "../../pool/pool.h"
#include "kronknet/utils/monotonic.h"

static int __knServer_accept(
    knServer *server
)
{
    knConnection *newConn = NULL;

    if (!server)
        return KNEVTARGS;
    newConn = knConnection_accept(server);
    if (!newConn)
        return KNEVTERR;
    knInfo(server->logger, "Connection [%d] from %s:%d", newConn->on_tcp.fd, newConn->ip, newConn->port);
    if (knPool_registerFd(&server->pool, newConn->on_tcp.fd, newConn, POLLIN) != KNEVTOK) {
            knError(server->logger, "Connection [%d]: failed to add to pool", newConn->on_tcp.fd);
            return KNEVTERR;
    }
    knInfo(server->logger, "Connection [%d]: added to pool", newConn->on_tcp.fd);
    if (server->onConnection) {
        switch (server->onConnection(server, newConn)) {
            case KNEVTOK:
                break;
            default:
                knError(server->logger, "Connection [%d]: Error on \"onConnection\" callback", newConn->on_tcp.fd);
                knServer_kick(server, newConn);
                return KNEVTKICK;
        }
    }
    return KNEVTOK;
}

static int __knServer_receiveData(
    knServer *server,
    knConnection *conn
)
{
    uint8_t kronkbuffer[KNBUFFSIZ] = {0};

    if (!server || !conn) {
        return KNEVTARGS;
    }
    ssize_t reads = recv(conn->on_tcp.fd, kronkbuffer, sizeof(kronkbuffer), 0);
    if (reads > 0) {
        knInfo(server->logger, "Connection [%d] sends %zd bytes", conn->id, reads);
        conn->last_data = monotonic();
        if (server->onRead) {
            server->onRead(conn, kronkbuffer, reads);
        }
    } else if (reads == 0) {
        knError(server->logger, "Connection [%d]: connection lost", conn->id);
        return KNEVTKICK;
    } else {
        if (errno != EAGAIN && errno != EWOULDBLOCK) {
            knError(server->logger, "Connection [%d]: connection lost", conn->id);
            return KNEVTKICK;
        }
    }
    return KNEVTOK;
}


int knServer_tcpPollinHook(
    knServer* server,
    size_t *idx
)
{
    if (server->pool.pollfds[*idx].fd == server->fd) {
        knInfo(server->logger, "New connection request received");
        if (__knServer_accept(server) != KNEVTOK) {
            knError(server->logger, "Connection request declined");
        }
    } else {
        knInfo(server->logger, "Data received");
        switch (__knServer_receiveData(server, server->pool.conns[*idx])) {
            case KNEVTERR:
                knError(server->logger, "Connection [%d]: Error while receiving data", server->pool.conns[*idx]->id);
                break;
            case KNEVTKICK:
                knServer_kickAtIndex(server, *idx);
                (*idx)--;
                break;
            default:
                break;
        }
    }
    return KNEVTOK;
}
