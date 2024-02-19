/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** client.c
*/
#include "myteams_server.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

bool is_empty_client(client_t *head)
{
    return head == NULL;
}

void delete_client(client_t **head, char *uuid)
{
    client_t *current = *head;
    client_t *tmp = NULL;

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

void delete_all_clients(client_t **head)
{
    client_t *current = *head;
    client_t *tmp = current;

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

client_t *find_client_by_fd(client_t *head, int fd)
{
    client_t *current = head;

    if (head == NULL)
        return NULL;
    while (current->fd != fd) {
        if (current->next == NULL)
            return NULL;
        else
            current = current->next;
    }
    return current;
}

void add_client(client_t **head, int fd)
{
    client_t *current = (*head);
    client_t *client = my_malloc(sizeof(client_t));

    client->uuid = strdup("");
    client->fd = fd;
    client->username = strdup("Anonymous");
    client->is_connected = false;
    client->next = NULL;
    client->subscribed_team = NULL;
    if ((*head) == NULL)
        (*head) = client;
    else {
        while (current->next != NULL)
            current = current->next;
        current->next = client;
    }
}
