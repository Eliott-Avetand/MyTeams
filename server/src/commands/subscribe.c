/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** subscribe.c
*/
#include "myteams_server.h"
#include <stdio.h>

void subscribe(server_t *server, client_t *client, char **args)
{
    team_t *team = NULL;

    if (check_commands_args(2, args)) {
        team = find_team(server->teams, args[1]);
        if (team) {
            dprintf(client->fd, "[700] Command okay.\r\n\x4");
            dprintf(client->fd, "%s\x3%s\r\n\x4", client->uuid, team->uuid);
            add_client_subscription(client, team->name, team->uuid);
            add_team_subscription(team, client->username, client->uuid);
        } else {
            dprintf(client->fd,
            "[712] Invalid uuid, team doesn't exists.\r\n\x4");
            dprintf(client->fd, "%s\r\n\x4", args[1]);
        }
    } else
        dprintf(client->fd, "[750] Wrong number of arguments.\r\n\x4");
}
