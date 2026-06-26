/*
** EPITECH PROJECT, 2026
** KRONKNET
** File description:
** Stop the server
*/
#include "kronknet/callback/callback.h"
#include "../server.h"
#include "kronknet/macros/optimization.h"
#include <stdbool.h>

KN_API
void knServer_stop(
    knServer *server
)
{
    if (!server)
        return;
    server->running = false;
}
