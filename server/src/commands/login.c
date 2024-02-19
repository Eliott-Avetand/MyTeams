/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** login.c
*/
#include "myteams_server.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void login(server_t *server, client_t *client, char **args)
{
    client_t *user = NULL;

    if (check_commands_args(2, args)) {
        user = find_client_by_name(server->clients, args[1]);
        free(client->username);
        client->username = strdup(args[1]);
        client->uuid = user == NULL ? generate_uuid() : strdup(user->uuid);
        client->is_connected = true;
        if (user == NULL)
            server_event_user_created(client->uuid, args[1]);
        server_event_user_logged_in(client->uuid);
        dprintf(client->fd, "[100] Sucessfuly logged in.\r\n\x4");
        dprintf(client->fd, "%s\x3%s\r\n\x4", client->uuid, client->username);
    } else
        dprintf(client->fd, "[150] Wrong number of arguments.\r\n\x4");
    (void)server;
}
