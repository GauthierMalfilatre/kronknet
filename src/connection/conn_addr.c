/*
** EPITECH PROJECT, 2026
** KRONKNET
** File description:
** Get the addr (ip | port) of the connection
*/
#include "kronknet/connection/connection.h"
#include <stdint.h>

const char *knConnection_getIp(const knConnection *conn)
{
    return conn->ip;
}

uint16_t knConnection_getPort(const knConnection *conn)
{
    return conn->port;
}
