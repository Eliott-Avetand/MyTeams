/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** users.c
*/
#include "myteams_server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *malloc_buffer(client_t *client_head)
{
    client_t *current = client_head;
    char *buf = NULL;
    int total_len = 0;

    while (current != NULL) {
        total_len += strlen(current->uuid) + strlen(current->username) + 5;
        current = current->next;
    }
    total_len += 20;
    buf = my_malloc(total_len);
    return buf;
}

char *concat_clients_info(client_t *client_head)
{
    client_t *current = client_head;
    char *buf = malloc_buffer(client_head);
    int actual_len = 0;

    while (current != NULL) {
        actual_len += sprintf(buf + actual_len, "%s\x3%s\x3%d\r\n",
        current->uuid, current->username, current->is_connected);
        current = current->next;
    }
    buf[actual_len++] = '\x4';
    buf[actual_len] = '\0';
    return buf;
}

void users(server_t *server, client_t *client, char **args)
{
    client_t *current = server->clients;
    char *buf = NULL;

    if (check_commands_args(1, args)) {
        dprintf(client->fd, "[300] Command okay.\r\n\x4");
        if (current == NULL)
            dprintf(client->fd, "None\r\n\x4");
        buf = concat_clients_info(current);
        write(client->fd, buf, strlen(buf));
    } else
        dprintf(client->fd, "[350] Wrong number of arguments.\r\n\x4");
}
