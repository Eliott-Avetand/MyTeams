/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** create.c
*/
#include "myteams_server.h"
#include <stdio.h>

void create(server_t *server, client_t *client, char **args)
{
    if (check_commands_args(3, args)) {
        add_team(&server->teams, args[1], args[2], client->context);
    } else
        dprintf(client->fd, "[1050] Wrong number of arguments.\r\n\x4");
}
