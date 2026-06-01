/*
** EPITECH PROJECT, 2026
** KRONKNET
** File description:
** Set the logging, on or off.
*/
#include "kronknet/server/server.h"
#include <stdarg.h>
#include <stdbool.h>

void knServer_setLogging(knServer *server, bool shouldLog)
{
    if (!server) {
        return;
    }
    server->logs = shouldLog;
}
