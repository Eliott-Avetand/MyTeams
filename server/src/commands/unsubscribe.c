/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** unsubscribe.c
*/
#include "myteams_server.h"
#include <stdio.h>

void unsubscribe(server_t *server, client_t *client, char **args)
{
    team_t *team = NULL;

    if (check_commands_args(2, args)) {
        team = find_team(server->teams, args[1]);
        if (team) {
            dprintf(client->fd, "[900] Command okay.\r\n\x4");
            dprintf(client->fd, "%s\x3%s\r\n\x4", client->uuid, team->uuid);
            delete_subscription(&client->subscribed_team, client->uuid);
            delete_subscription(&team->subscribed_user, team->uuid);
        } else {
            dprintf(client->fd,
            "[912] Invalid uuid, team doesn't exists.\r\n\x4");
            dprintf(client->fd, "%s\r\n\x4", args[1]);
        }
    } else
        dprintf(client->fd, "[950] Wrong number of arguments.\r\n\x4");
}
