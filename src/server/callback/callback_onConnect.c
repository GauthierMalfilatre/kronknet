/*
** EPITECH PROJECT, 2026
** KRONKNET
** File description:
** Set onConnect callback
*/
#include "kronknet/connection/connection.h"
#include "kronknet/server/callback/callback.h"
#include "kronknet/server/server.h"

int knCallback_onConnection(knServer *server, knConnectionCb callback)
{
    if (!server) {
        return -1;
    }
    server->onConnection = callback;
    return 0;
}
