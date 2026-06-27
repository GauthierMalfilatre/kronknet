/*
** FREE PROJECT, 2026
** KRONKNET
** File description:
** Get time in ms from a monotonic clock.
*/
#pragma once
#include "kronknet/macros/optimization.h"
#include <time.h>
#include <stdint.h>

typedef uint64_t timestamp;

KN_HOT
static inline timestamp monotonic(void)
{
    struct timespec ts;

    if (clock_gettime(CLOCK_MONOTONIC, &ts) == -1) {
        return 0;
    }
    return (uint64_t)(ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
}
