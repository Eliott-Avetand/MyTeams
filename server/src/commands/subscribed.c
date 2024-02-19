/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** subscribed.c
*/
#include "myteams_server.h"
#include <stdio.h>

void subscribed(server_t *server, client_t *client, char **args)
{
    team_t *team = NULL;
    subscription_t *current = NULL;

    if (check_commands_args(1, args)) {
        dprintf(client->fd, "[800] Command okay.\r\n\x4");
        current = client->subscribed_team;
    } else if (check_commands_args(2, args)) {
        team = find_team(server->teams, args[1]);
        if (team) {
            dprintf(client->fd, "[800] Command okay.\r\n\x4");
            current = team->subscribed_user;
        } else {
            dprintf(client->fd,
            "[812] Invalid uuid, team doesn't exists.\r\n\x4");
            dprintf(client->fd, "%s\r\n\x4", args[1]);
        }
    } else
        dprintf(client->fd, "[850] Wrong number of arguments.\r\n\x4");
}
