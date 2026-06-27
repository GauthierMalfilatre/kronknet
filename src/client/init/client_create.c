/*
** FREE PROJECT, 2026
** KRONKNET
** File description:
** Create client structure
*/
#include "kronknet/callback/callback.h"
#include "kronknet/client/client.h"
#include "kronknet/macros/errdef.h"
#include <arpa/inet.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/socket.h>
#include <unistd.h>
#include "../client.h"
#include "kronknet/macros/types.h"

KN_API
knClient *knClient_create(
    knFlags flags
)
{
    knClient *client = NULL;

    client = calloc(1, sizeof(knClient));
    if (!client) {
        return NULL;
    }
    if (knClient_init(client, flags) != KNEVTOK) {
        knClient_destroy(client);
        return NULL;
    }
    return client;
}
