/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** send.c
*/
#include "myteams_server.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void send_message(server_t *server, client_t *client, char **args)
{
    client_t *user = NULL;
    message_t *message = NULL;

    if (check_commands_args(3, args)) {
        if ((user = find_client_by_uuid(client, args[1])) != NULL) {
            message = create_message(client->uuid, user->uuid, args[2]);
            add_message(&(client->messages), message);
            dprintf(client->fd, "[500] Command okay.\r\n\x4");
            dprintf(client->fd, "None\r\n\x4");
            dprintf(user->fd, "[3000] Message received.\r\n\x4");
            dprintf(user->fd, "%s\x3%s\r\n\x4", client->uuid, args[2]);
            server_event_private_message_sended(client->uuid,
            user->uuid, args[2]);
        } else {
            dprintf(client->fd,
            "[511] Invalid uuid, user doesn't exists.\r\n\x4");
            dprintf(client->fd, "%s\r\n\x4", args[1]);
        }
    } else
        dprintf(client->fd, "[550] Wrong number of arguments.\r\n");
}
