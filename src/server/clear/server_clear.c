/*
** FREE PROJECT, 2026
** KRONKNET
** File description:
** Clear the server
*/
#include "kronknet/macros/types.h"
#include "kronknet/server/server.h"
#include <unistd.h>
#include "../pool/pool.h"
#include "../server.h"
#include "kronknet/utils/hashmap/hashmap.h"

void knServer_clear(
    knServer *server
)
{
    if (!server) {
        return;
    }
    if (server->fd != -1) {
        close(server->fd);
    }
    if (server->onDestroyHook) {
        server->onDestroyHook(server);
    }
    knPool_clear(&server->pool);
}
