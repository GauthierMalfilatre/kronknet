/*
** EPITECH PROJECT, 2026
** KRONKNET
** File description:
** Send message to a connection
*/
#include "kronknet/connection/connection.h"
#include "kronknet/errdef.h"
#include <asm-generic/errno-base.h>
#include <asm-generic/errno.h>
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>

int knConnection_send(knConnection *conn, const void *data, size_t size)
{
    if (!conn || !data || size == 0) {
        return KNEVTARGS;
    }
    ssize_t written = send(conn->fd, data, size, MSG_NOSIGNAL);
    if (written > 0) {
        if ((size_t)written == size) {
            return KNEVTOK;
        }
    } else if (written == -1) {
        if (errno != EAGAIN && errno != EWOULDBLOCK) {
            return KNEVTKICK;
        }
        written = 0;
    }
    // TODO: internal ring buffer
    //size_t remaining = size - written;
    return KNEVTOK;
}
