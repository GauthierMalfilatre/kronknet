/*
** EPITECH PROJECT, 2026
** KRONKNET
** File description:
** Set onDisconection callback
*/
#include "kronknet/macros/errdef.h"
#include "kronknet/callback/callback.h"
#include "kronknet/client/client.h"

int knClient_onDisconnectionCallback(knClient *client, knClientCb callback)
{
    if (!client) {
        return KNEVTARGS;
    }
    client->onDisconnection = callback;
    return KNEVTOK;
}
