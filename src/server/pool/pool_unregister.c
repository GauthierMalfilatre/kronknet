/*
** EPITECH PROJECT, 2026
** KRONKNET
** File description:
** Unregister an fd for the server's poll
*/
#include "kronknet/server/pool/pool.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <sys/poll.h>

int knPool_unregister(knPool *pool, int fd)
{
    if (!pool || fd == -1) {
        return -1;
    }
    for (size_t i = 0; i < pool->count; ++i) {
        if (pool->pollfds[i].fd == fd) {
            pool->pollfds[i] = pool->pollfds[pool->count - 1];
            pool->pollfds[pool->count - 1] = (struct pollfd){
                -1,
                0,
                0
            };
            return 0;
        }
    }
    return -1;
}

int knPool_unregisterOnIndex(knPool *pool, size_t index)
{
    if (!pool || index == -1UL || index >= pool->count) {
        return -1;
    }
    pool->pollfds[index] = pool->pollfds[pool->count - 1];
    pool->pollfds[pool->count - 1] = (struct pollfd){
        -1,
        0,
        0
    };
    return 0;
}
