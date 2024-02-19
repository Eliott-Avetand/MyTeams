/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** logout.c
*/
#include "myteams_server.h"
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>

void logout(server_t *server, client_t *client, char **args)
{
    if (check_commands_args(1, args)) {
        dprintf(client->fd, "[200] Sucessfuly logged out.\r\n\x4");
        dprintf(client->fd, "%s\x3%s\r\n\x4", client->uuid, client->username);
        client->is_connected = false;
        shutdown(client->fd, SHUT_RDWR);
        close(client->fd);
        server_event_user_logged_out(client->uuid);
        FD_CLR(client->fd, &server->main_set);
    } else
        dprintf(client->fd, "[250] Wrong number of arguments.\r\n\x4");
}
