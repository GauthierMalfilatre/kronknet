/*
** FREE PROJECT, 2026
** KRONKNET
** File description:
** Server udp destroy hook
*/
#include "../../server.h"
#include "kronknet/utils/hashmap/hashmap.h"

void knServer_udpDestroyHook(
    knServer* server
)
{
    knMap_destroy(server->on_udp.connections);
}
