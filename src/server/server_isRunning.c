/*
** EPITECH PROJECT, 2026
** KRONKNET
** File description:
** Is the server running ??
*/
#include "kronknet/server/server.h"
#include <stdbool.h>

bool knServer_isRunning(const knServer *server)
{
    if (!server)
        return false;
    return server->running;
}
