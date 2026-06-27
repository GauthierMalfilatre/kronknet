/*
** FREE PROJECT, 2026
** KRONKNET
** File description:
** Foreach map
*/
#include "kronknet/macros/optimization.h"
#include "kronknet/utils/hashmap/hashmap.h"
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include "hashmap.h"

KN_API
void knMap_foreach(
    const knMap *map,
    knMapFunction function,
    void* arg
)
{
    knMapNode* next = NULL;

    if (!map || !function || map->size == 0) {
        return;
    }
    for (size_t i = 0; i < map->size; ++i) {
        knMapNode* node = map->raw[i];
        while (node) {
            next = node->next;
            function(node->key, node->data, arg);
            node = next;
        }
    }
}
