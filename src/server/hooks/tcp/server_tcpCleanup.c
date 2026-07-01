/*
** FREE PROJECT, 2026
** KRONKNET
** File description:
** Server tcp cleanup hook
*/
#include "../../server.h"
#include "../../../connection/connection.h"
#include "kronknet/callback/callback.h"
#include "kronknet/connection/connection.h"
#include "kronknet/utils/monotonic.h"

void knServer_tcpCleanupHook(
    knServer* server
)
{
    for (int i = (int)server->pool.count - 1; i >= 1; --i) {
        if (server->pool.conns[i] && (server->pool.conns[i]->disconnected || (server->connection_timeout > 0 &&
            (monotonic() - server->pool.conns[i]->last_data) > server->connection_timeout))) {
            knWarn(server->logger, "Kicking connection <%zu>, reason: inactivity", knConnection_getId(server->pool.conns[i]));
            knServer_kickAtIndex(server, i);
        }
    }
}
