/*
** FREE PROJECT, 2026
** KRONKNET
** File description:
** Server struct definition
*/
#ifndef KRONKNET_SERVER_UDP_H
    #define KRONKNET_SERVER_UDP_H
    #include "kronknet/callback/callback.h"

int knServer_udpPolloutHook(knServer* server, size_t *idx);
int knServer_udpPollinHook(knServer* server, size_t *idx);
void knServer_udpCleanupHook(knServer* server);
void knServer_udpDestroyHook(knServer* server);

#endif /* KRONKNET_SERVER_UDP_H */
