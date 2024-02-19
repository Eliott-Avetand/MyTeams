/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** user.c
*/
#include "myteams_server.h"
#include <stdio.h>

void user(server_t *server, client_t *client, char **args)
{
    client_t *user = NULL;

    if (check_commands_args(2, args)) {
        user = find_client_by_uuid(client, args[1]);
        if (user) {
            dprintf(client->fd, "[400] Command okay.\r\n\x4");
            dprintf(client->fd, "%s\x3%s\x3%d\r\n\x4",
            user->uuid, user->username, user->is_connected);
        } else {
            dprintf(client->fd,
            "[411] Invalid uuid, user doesn't exists.\r\n\x4");
            dprintf(client->fd, "%s\r\n\x4", args[1]);
        }
    } else
        dprintf(client->fd, "[450] Wrong number of arguments.\r\n\x4");
    (void)server;
}
