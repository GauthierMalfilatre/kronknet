/*
** EPITECH PROJECT, 2026
** KRONKNET
** File description:
** Set the logging, on or off.
*/
#include "kronknet/macros/types.h"
#include <stdarg.h>
#include <stdbool.h>
#include "../server.h"

void knServer_setLogging(
    knServer *server,
    knBool shouldLog
)
{
    if (!server) {
        return;
    }
    server->logs = shouldLog;
}
