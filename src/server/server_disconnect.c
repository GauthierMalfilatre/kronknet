/*
** EPITECH PROJECT, 2026
** KRONKNET
** File description:
** Disconnect a client
*/
#include "kronknet/callback/callback.h"
#include "kronknet/server/server.h"
#include <stdbool.h>
#include <stddef.h>
#include "kronknet/connection/connection.h"

void knServer_disconnect(knServer *server, knConnection *conn)
{
    if (!server || !conn) {
        return;
    }
    conn->disconnected = true;
}
