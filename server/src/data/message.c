/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** message.c
*/
#include "myteams_server.h"
#include <string.h>
#include <stdlib.h>

bool is_empty_message(message_t *head)
{
    return head == NULL;
}

void delete_message(message_t **head, char *uuid)
{
    message_t *current = *head;
    message_t *tmp = NULL;

    if (current == NULL)
        return;
    if (strcmp((*head)->uuid, uuid) == 0) {
        tmp = (*head);
        (*head) = (*head)->next;
    } else {
        while (current->next != NULL && strcmp(current->next->uuid, uuid) != 0)
            current = current->next;
        tmp = current->next;
        current->next = tmp->next;
    }
    free(tmp->uuid);
    free(tmp);
}

void delete_all_messages(message_t **head)
{
    message_t *current = *head;
    message_t *tmp = current;

    if (current == NULL)
        return;
    while (current->next != NULL) {
        tmp = current;
        current = current->next;
        free(tmp->uuid);
        free(tmp);
    }
    free(current->uuid);
    free(current);
}

message_t *find_message(message_t *head, char *uuid)
{
    message_t *current = head;

    if (head == NULL)
        return NULL;
    while (strcmp(current->uuid, uuid) != 0) {
        if (current->next == NULL)
            return NULL;
        else
            current = current->next;
    }
    return current;
}

void add_message(message_t **head, message_t *message)
{
    message_t *current = (*head);

    message->next = NULL;
    if ((*head) == NULL)
        (*head) = message;
    else {
        while (current->next != NULL)
            current = current->next;
        current->next = message;
    }
}
