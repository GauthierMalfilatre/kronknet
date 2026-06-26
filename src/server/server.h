/*
** EPITECH PROJECT, 2026
** KRONKNET
** File description:
** Server struct definition
*/
#ifndef KRONKNET_SERVER_IMPL_H
    #define KRONKNET_SERVER_IMPL_H
    #include "kronknet/callback/callback.h"
    #include "kronknet/macros/types.h"
    #include <stdbool.h>
    #include "pool/pool.h"
    #include "../utils/logger/logger.h"

///////////////////////////////////////////////////////////////////////////////
/**
 * @struct  server_s
 *
 * @brief   Server structure, containing necessary datas: pollfds, addr, ...
 */
///////////////////////////////////////////////////////////////////////////////
typedef struct kronknet_server_s {

    knBool             running;              //!< Is the server running
    knBool             logs;                 //!< Is the server should produce logs
    int                fd;                   //!< The fd of the server socket
    struct sockaddr_in addr;                 //!< The address of the server
    knPool             pool;                 //!< The pool of pollfds to look on
    void              *user_ptr;             //!< Data like a struct given by the user
    knConnectionCb     onConnection;         //!< onConnection callback
    knReadCb           onRead;               //!< onRead callback
    knEventCb          onWrite;              //!< onWrite callback
    knConnectionCb     onDisconnection;      //!< onDisconnection callback
    char               ip[INET_ADDRSTRLEN];  //!< The ip as a string
    knLoggerData       logger;               //!< The data of the logger

} knServer;
///////////////////////////////////////////////////////////////////////////////

// TODO: Documentation
void knServer_kick(knServer *server, knConnection *conn);
void knServer_kickAtIndex(knServer *server, size_t idx);

int knServer_receiveData(knServer *server, knConnection *conn);
int knServer_accept(knServer *server);

#endif /* KRONKNET_SERVER_IMPL_H */
