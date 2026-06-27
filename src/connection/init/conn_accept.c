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
#include <sys/socket.h>
#include <unistd.h>
#include "../../server/server.h"

knConnection *knConnection_accept(
    const knServer *server
)
{
    knConnection *conn;
    int flags;
    int fd;
    struct sockaddr_in addr;
    socklen_t len = sizeof(addr);

    fd = accept(server->fd, (struct sockaddr *)&addr, &len);
    if (fd == -1) {
        return NULL;
    }
    flags = fcntl(fd, F_GETFL, 0);
    if (flags != -1)
        fcntl(fd, F_SETFL, flags | O_NONBLOCK);
    conn = knConnection_create(&addr, server->flags);
    if (!conn) {
        close(fd);
        return NULL;
    }
    conn->fd = fd;
    return conn;
}
