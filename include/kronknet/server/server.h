/*
** EPITECH PROJECT, 2026
** KRONKNET
** File description:
** Server struct definition
*/
#ifndef KRONKNET_SERVER_H
    #define KRONKNET_SERVER_H
    #include "kronknet/callback/callback.h"
    #include "kronknet/macros/types.h"
    #include "kronknet/macros/optimization.h"

typedef struct kronknet_server_s knServer;

// TODO: Documentation
KN_API knServer *knServer_create(uint16_t port);
KN_API int knServer_init(knServer *server, uint16_t port);
KN_API void knServer_clear(knServer *server);
KN_API void knServer_destroy(knServer *server);
KN_API int knServer_runOnce(knServer *server, ssize_t timeoutMs);
KN_API int knServer_run(knServer *server);

// FIXME: Move
KN_API void knConnection_disconnect(knConnection *conn);

KN_API bool knServer_isRunning(const knServer *server);

KN_API void *knServer_getUserPtr(const knServer *server);
KN_API void  knServer_setUserPtr(knServer *server, void *data);

KN_API const char *knServer_getIp(const knServer *server);
KN_API knPort      knServer_getPort(const knServer *server);

#endif /* KRONKNET_SERVER_H */
