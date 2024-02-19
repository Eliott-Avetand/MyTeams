/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** use.c
*/
#include "myteams_server.h"
#include <stdio.h>
#include <string.h>

void use(server_t *server, client_t *client, char **args)
{
    if (check_commands_args(2, args)) {
        client->context = strdup(args[1]);
    } else
        dprintf(client->fd, "[1050] Wrong number of arguments.\r\n\x4");
    (void)server;
}
