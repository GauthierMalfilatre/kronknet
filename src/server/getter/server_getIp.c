/*
** EPITECH PROJECT, 2026
** KRONKNET
** File description:
** Get the ip of the server (but useless asf)
*/
#include "kronknet/callback/callback.h"
#include "kronknet/macros/optimization.h"
#include "kronknet/server/server.h"
#include "../server.h"

KN_API
const char *knServer_getIp(
    const knServer *server
)
{
    if (!server)
        return NULL;
    return server->ip;
}
