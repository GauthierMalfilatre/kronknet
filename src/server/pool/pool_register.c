/*
** EPITECH PROJECT, 2026
** KRONKNET
** File description:
** Register an fd for the server's pool
*/
#include "kronknet/server/pool/pool.h"
#include <stdlib.h>
#include <string.h>
#include <sys/poll.h>

static int __knPool_ensureCapacity(knPool *pool, size_t size)
{
    if (!pool) {
        return -1;
    }
    while (pool->size < size) {
        pool->pollfds = realloc(pool->pollfds, sizeof(struct pollfd)
            * pool->size * 2);
        if (pool->pollfds == NULL) {
            return -1;
        }
        memset(&pool->pollfds[pool->size], 0,
            sizeof(struct pollfd) * pool->size);
        pool->size *= 2;
    }
    return 0;
}

int knPool_register(knPool *pool, int fd, int events)
{
    size_t new_count = 0;

    if (!pool || fd == -1) {
        return -1;
    }
    new_count = pool->count + 1;
    if (__knPool_ensureCapacity(pool, new_count) == -1) {
        return -1;
    }
    pool->pollfds[pool->count].fd = fd;
    pool->pollfds[pool->count].events = events;
    pool->count = new_count;
    return 0;
}
