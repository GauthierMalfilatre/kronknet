/*
** EPITECH PROJECT, 2026
** KRONKNET
** File description:
** Get logging data
*/
#include "kronknet/callback/callback.h"
#include "kronknet/client/client.h"
#include "../client.h"
#include "kronknet/macros/types.h"

KN_API
knLogLevel knClient_getLogLevel(
    const knClient *client
)
{
    if (!client) {
        return knLogNone;
    }
    return client->logger.log_level;
}

KN_API
FILE* knClient_getLogOutput(
    const knClient *client
)
{
    if (!client) {
        return NULL;
    }
    return client->logger.out;
}
