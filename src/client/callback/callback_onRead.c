/*
** EPITECH PROJECT, 2026
** KRONKNET
** File description:
** Set onRead callback
*/
#include "kronknet/macros/errdef.h"
#include "kronknet/callback/callback.h"
#include "kronknet/client/client.h"

int knClient_onReadCallback(knClient *client, knClientReadCb callback)
{
    if (!client) {
        return KNEVTARGS;
    }
    client->onRead = callback;
    return KNEVTOK;
}
