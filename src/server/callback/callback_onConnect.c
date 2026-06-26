/*
** EPITECH PROJECT, 2026
** KRONKNET
** File description:
** Set onConnect callback
*/
#include "kronknet/connection/connection.h"
#include "kronknet/macros/errdef.h"
#include "kronknet/callback/callback.h"
#include "kronknet/server/server.h"
#include "../server.h"

int knServer_setOnConnect(
    knServer *server,
    knConnectionCb callback
)
{
    if (!server) {
        return KNEVTARGS;
    }
    server->onConnection = callback;
    return KNEVTOK;
}
