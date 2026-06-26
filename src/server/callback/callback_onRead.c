/*
** EPITECH PROJECT, 2026
** KRONKNET
** File description:
** Set onRead callback
*/
#include "kronknet/connection/connection.h"
#include "kronknet/macros/errdef.h"
#include "kronknet/callback/callback.h"
#include "kronknet/server/server.h"
#include "../server.h"

int knServer_setOnRead(
    knServer *server,
    knReadCb callback)
{
    if (!server) {
        return KNEVTARGS;
    }
    server->onRead = callback;
    return KNEVTOK;
}
