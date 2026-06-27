/*
** FREE PROJECT, 2026
** KRONKNET
** File description:
** Run the server. main loop.
*/
#include "kronknet/macros/errdef.h"
#include "kronknet/callback/callback.h"
#include "kronknet/connection/connection.h"
#include "kronknet/macros/types.h"
#include "kronknet/server/server.h"
#include "kronknet/utils/hashmap/hashmap.h"
#include <netinet/in.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/socket.h>
#include "server.h"
#include "../connection/connection.h"

int knServer_onPollinUDP(
    knServer *server
)
{
    struct sockaddr_in addr = {};
    socklen_t addr_len = sizeof(addr);
    uint8_t buffer[KNBUFFSIZ];
    knConnection *conn = NULL;

    if (!server || !(server->flags & knUDP)) {
        return -1;
    }
    ssize_t reads = recvfrom(server->fd, buffer, sizeof(buffer), 0, (struct sockaddr *)&addr, &addr_len);

    if (reads < 0) {
        return KNEVTOK;
    }
    uint64_t key = ((uint64_t)addr.sin_port << 32 | (uint64_t)addr.sin_port);
    conn = knMap_search(server->on_udp.hashmap, key);
    if (!conn) {
        conn = knConnection_create(&addr);
        if (!conn) {
            return -1;
        }
        if (knMap_insert(server->on_udp.hashmap, key, conn, (knMapDeleter)&knConnection_destroy) == -1) {
            return -1;
        }
        if (server->onConnection) {
            server->onConnection(server, conn);
        }
    }
    if (server->onRead) {
        server->onRead(conn, buffer, (size_t)reads);
    }
    return 0;
}
