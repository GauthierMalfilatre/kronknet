/*
** EPITECH PROJECT, 2026
** KRONKNET
** File description:
** Init poolfd
*/
#include "kronknet/server/pool/pool.h"
#include <stdlib.h>
#include <sys/poll.h>

int knPool_init(knPool *pool)
{
    if (!pool) {
        return -1;
    }
    pool->count = 0;
    pool->size = 1;
    pool->pollfds = calloc(pool->size, sizeof(struct pollfd));
    if (!pool->pollfds) {
        return -1;
    }
    return 0;
}
