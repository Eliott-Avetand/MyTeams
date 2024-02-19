/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** help.c
*/
#include "myteams_server.h"
#include <stdio.h>

void help(server_t *server, client_t *client, char **args)
{
    if (check_commands_args(1, args)) {
        dprintf(client->fd, "[000] Commande okay.\r\n\x4");
        dprintf(client->fd, "C'est les commandes du sujet.\r\n\x4");
    } else
        dprintf(client->fd, "[050] Wrong number of arguments.\r\n\x4");
    (void)server;
}
