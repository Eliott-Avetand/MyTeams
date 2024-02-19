/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** messages.c
*/
#include "myteams_server.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

char *malloc_buffer_2(message_t *msg_head)
{
    message_t *current = msg_head;
    char *buf = NULL;
    int total_len = 0;

    while (current != NULL) {
        total_len += strlen(current->author_uuid)
        + strlen(current->message_body) + 10 + 4;
        current = current->next;
    }
    total_len += 20;
    buf = my_malloc(total_len);
    return buf;
}

char *concat_messages_info(message_t *msg_head)
{
    message_t *current = msg_head;
    char *buf = malloc_buffer_2(msg_head);
    int actual_len = 0;

    while (current != NULL) {
        actual_len += sprintf(buf + actual_len, "%s\x3%lu\x3%s\r\n",
        current->author_uuid, current->timestamp, current->message_body);
        current = current->next;
    }
    buf[actual_len++] = '\x4';
    buf[actual_len] = '\0';
    return buf;
}

void messages(server_t *server, client_t *client, char **args)
{
    client_t *user = NULL;
    char *buf = NULL;

    if (check_commands_args(2, args)) {
        if ((user = find_client_by_uuid(client, args[1])) == NULL) {
            dprintf(client->fd,
            "[611] Invalid uuid, user doesn't exists.\r\n\x4");
            dprintf(client->fd, "%s\r\n\x4", args[1]);
            return;
        }
        dprintf(client->fd, "[600] Command okay.\r\n\x4");
        buf = concat_messages_info(user->messages);
        write(client->fd, buf, strlen(buf));

    }
    (void)server;
}
