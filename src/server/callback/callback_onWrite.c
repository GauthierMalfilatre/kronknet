/*
** EPITECH PROJECT, 2026
** KRONKNET
** File description:
** Set onWrite callback
*/
#include "kronknet/connection/connection.h"
#include "kronknet/macros/errdef.h"
#include "kronknet/callback/callback.h"
#include "kronknet/server/server.h"
#include "../server.h"

int knServer_setOnWrite(
    knServer *server,
    knEventCb callback
)
{
    if (!server) {
        return KNEVTARGS;
    }
    server->onWrite = callback;
    return KNEVTOK;
}
