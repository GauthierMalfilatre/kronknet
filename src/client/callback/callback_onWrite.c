/*
** EPITECH PROJECT, 2026
** KRONKNET
** File description:
** Set onWrite callback
*/
#include "kronknet/macros/errdef.h"
#include "kronknet/callback/callback.h"
#include "kronknet/client/client.h"

int knClient_onWriteCallback(knClient *client, knClientCb callback)
{
    if (!client) {
        return KNEVTARGS;
    }
    client->onWrite = callback;
    return KNEVTOK;
}
