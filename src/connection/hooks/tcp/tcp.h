/*
** FREE PROJECT, 2026
** KRONKNET
** File description:
** Server struct definition
*/
#ifndef KRONKNET_CONNECTION_TCP_H
    #define KRONKNET_CONNECTION_TCP_H
    #include "../../connection.h"

int knConnection_tcpSendHook(knConnection *conn, const void *data, size_t size);

#endif /* KRONKNET_CONNECTION_TCP_H */
