/*
** FREE PROJECT, 2026
** KRONKNET
** File description:
** Server tcp cleanup hook
*/
#include "../../server.h"
#include "../../../connection/connection.h"

void knServer_tcpCleanupHook(
    knServer* server
)
{
    for (int i = (int)server->pool.count - 1; i >= 1; --i) {
        if (server->pool.conns[i] && server->pool.conns[i]->disconnected) {
            knServer_kickAtIndex(server, i);
        }
    }
}
