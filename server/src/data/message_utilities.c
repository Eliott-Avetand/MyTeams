/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** message_utilities.c
*/
#include "myteams_server.h"
#include <string.h>
#include <stdlib.h>

message_t *create_message(char *author_uuid,
char *recipient_uuid, char *message_body)
{
    message_t *message = my_malloc(sizeof(message_t));

    message->next = NULL;
    message->uuid = generate_uuid();
    message->author_uuid = strdup(author_uuid);
    message->recipient_uuid = strdup(recipient_uuid);
    message->timestamp = time(NULL);
    strncpy(message->message_body, message_body, MAX_BODY_LENGTH);
    return message;
}
