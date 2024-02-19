/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** channel.c
*/
#include "myteams_server.h"
#include <string.h>
#include <stdlib.h>

bool is_empty_channel(channel_t *head)
{
    return head == NULL;
}

void delete_channel(channel_t **head, char *uuid)
{
    channel_t *current = *head;
    channel_t *tmp = NULL;

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
    delete_all_threads(&tmp->threads);
    free(tmp->uuid);
    free(tmp);
}

void delete_all_channels(channel_t **head)
{
    channel_t *current = *head;
    channel_t *tmp = current;

    if (current == NULL)
        return;
    while (current->next != NULL) {
        tmp = current;
        current = current->next;
        delete_all_threads(&current->threads);
        free(tmp->uuid);
        free(tmp);
    }
    delete_all_threads(&current->threads);
    free(current->uuid);
    free(current);
}

channel_t *find_channel(channel_t *head, char *uuid)
{
    channel_t *current = head;

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

void add_channel(channel_t **head, char *uuid)
{
    channel_t *current = (*head);
    channel_t *channel = my_malloc(sizeof(channel_t));

    channel->uuid = uuid;
    channel->next = NULL;
    if ((*head) == NULL)
        (*head) = channel;
    else {
        while (current->next != NULL)
            current = current->next;
        current->next = channel;
    }
}
