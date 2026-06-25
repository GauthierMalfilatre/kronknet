/*
** EPITECH PROJECT, 2026
** KRONKNET
** File description:
** Get data
*/
#include "kronknet/callback/callback.h"
#include "kronknet/client/client.h"

void *knClient_getData(const knClient *client)
{
    if (!client) {
        return NULL;
    }
    return client->data;
}
