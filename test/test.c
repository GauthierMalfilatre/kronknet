/*
** EPITECH PROJECT, 2026
** ZAPPY
** File description:
** network library in C, for the zappy project
*/
#include "kronknet/server/server.h"
#include "kronknet/connection/connection.h"
#include "kronknet/server/callback/callback.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Player_s
{

    knConnection *conn;
    int x;

} Player;

int onConnectionCallback([[maybe_unused]] knServer *server, knConnection *conn)
{
    Player *player = malloc(sizeof(Player));

    if (!player)
        return -1;
    player->conn = conn;
    knConnection_setData(conn, player);
    printf("Hello guys from callback!!\n");
    return 0;
}

int onReadCallback([[maybe_unused]] knConnection *conn)
{
    Player *player = knConnection_getData(conn);

    if (!player)
        return -1;
    printf("I received: ");
    return 0;
}

int main(void)
{
    knServer *server = knServer_create(4242);

    knServer_setLogging(server, true);
    knCallback_onConnection(server, &onConnectionCallback);
    knServer_run(server);
    knServer_destroy(server);
    return 0;
}
