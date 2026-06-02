/*
** EPITECH PROJECT, 2026
** KRONKNET
** File description:
** Create the server
*/
#include "kronknet/server/server.h"
#include <stddef.h>
#include <stdlib.h>

knServer *knServer_create(uint16_t port)
{
    knServer *server = calloc(1, sizeof(knServer));

    if (!server) {
        return NULL;
    }
    if (knServer_init(server, port) == -1) {
        knServer_destroy(server);
        return NULL;
    }
    return server;
}
