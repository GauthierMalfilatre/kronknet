/*
** FREE PROJECT, 2026
** KRONKNET
** File description:
** Run the client
*/
#include "kronknet/client/client.h"
#include "kronknet/macros/errdef.h"
#include <arpa/inet.h>
#include <string.h>
#include <stdint.h>
#include <sys/socket.h>
#include "client.h"
#include "kronknet/macros/types.h"
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

KN_API
int knClient_connect(
    knClient *client,
    const char *ip,
    uint16_t port
)
{
    int type = SOCK_STREAM;
    int flags;

    if (!client || !ip || port == 0) {
        return KNEVTARGS;
    }
    knInfo(client->logger, "Connecting on %s:%d", ip, port);
    if (client->flags & knUDP) {
        type = SOCK_DGRAM;
    }
    client->fd = socket(AF_INET, type, 0);
    if (client->fd == -1) {
        knError(client->logger, "Error while creating socket");
        return KNEVTNET;
    }
    flags = fcntl(client->fd, F_GETFL, 0);
    if (flags != -1) {
        fcntl(client->fd, F_SETFL, flags | O_NONBLOCK);
    }
    client->addr.sin_family = AF_INET;
    client->addr.sin_port = htons(port);
    if (inet_pton(AF_INET, (!strcmp(ip, "localhost")) ? "127.0.0.1" : ip, &client->addr.sin_addr) != 1) {
        knError(client->logger, "Error while processing ip");
        close(client->fd);
        return KNEVTNET;
    }
    if (connect(client->fd, (struct sockaddr *)&client->addr, sizeof(client->addr)) == -1) {
        if (errno != EINPROGRESS) {
            knError(client->logger, "Error while connecting");
            close(client->fd);
            return KNEVTNET;
        }
    }
    if (client->onConnection) {
        client->onConnection(client);
    }
    return KNEVTOK;
}
