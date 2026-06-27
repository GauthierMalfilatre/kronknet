/*
** FREE PROJECT, 2026
** KRONKNET
** File description:
** Accept a connection
*/
#include "kronknet/connection/connection.h"
#include "kronknet/macros/errdef.h"
#include "pool/pool.h"
#include <sys/poll.h>
#include <sys/socket.h>
#include <unistd.h>
#include "../utils/logger/logger.h"
#include "server.h"
#include "../connection/connection.h"

int knServer_accept(
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
