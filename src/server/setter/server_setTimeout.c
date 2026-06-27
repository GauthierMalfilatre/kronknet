/*
** FREE PROJECT, 2026
** KRONKNET
** File description:
** Init the server
*/
#include "kronknet/callback/callback.h"
#include "../server.h"
#include "kronknet/macros/optimization.h"
#include "kronknet/utils/monotonic.h"

KN_API
void knServer_setConnectionTimeout(knServer *server, timestamp time)
{
    if (!server) {
        return;
    }
    server->connection_timeout = time;
}
