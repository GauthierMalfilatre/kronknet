/*
** FREE PROJECT, 2026
** KRONKNET
** File description:
** Accept a new connection
*/
#include "../connection.h"
#include "kronknet/connection/connection.h"
#include "kronknet/server/server.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stddef.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include "arpa/inet.h"
#include "kronknet/utils/rbuff/rbuff.h"
#include "../../server/server.h"

knConnection *knConnection_create(
    const struct sockaddr_in* addr
)
{
    knConnection *conn = calloc(1, sizeof(knConnection));
    static size_t id = 0;

    if (!conn)
        return NULL;
    conn->addr = *addr;
    conn->addr_length = sizeof(conn->addr);
    conn->on_tcp.fd = -1;
    conn->port = ntohs(conn->addr.sin_port);
    conn->id = id++;
    conn->disconnected = false;
    inet_ntop(AF_INET, &conn->addr.sin_addr, conn->ip, INET_ADDRSTRLEN);
    conn->out_buff = knRBuff_create(KNBUFFSIZ);
    if (!conn->out_buff) {
        knConnection_destroy(conn);
        return NULL;
    }
    return conn;
}
