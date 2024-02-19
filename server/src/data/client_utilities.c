/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** client_utilities.c
*/
#include "myteams_server.h"
#include <string.h>
#include <stdlib.h>

void add_client_subscription(client_t *client, char *name, char *uuid)
{
    subscription_t **current = &client->subscribed_team;
    subscription_t *subscription = malloc(sizeof(subscription_t));

    subscription->next = NULL;
    subscription->subscription_name = strdup(name);
    subscription->subscription_uuid = strdup(uuid);
    if ((*current) == NULL)
        (*current) = subscription;
    while ((*current)->next != NULL)
        (*current) = (*current)->next;
    (*current)->next = subscription;
}

void delete_subscription(subscription_t **head, char *uuid)
{
    subscription_t *current = *head;
    subscription_t *tmp = NULL;

    if (current == NULL)
        return;
    if (strcmp((*head)->subscription_uuid, uuid) == 0) {
        tmp = (*head);
        (*head) = (*head)->next;
    } else {
        while (current->next != NULL &&
        strcmp(current->next->subscription_uuid, uuid) != 0)
            current = current->next;
        tmp = current->next;
        current->next = tmp->next;
    }
    free(tmp->subscription_uuid);
    free(tmp->subscription_name);
    free(tmp);
}

client_t *find_client_by_uuid(client_t *head, char *uuid)
{
    client_t *current = head;

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

client_t *find_client_by_name(client_t *head, char *name)
{
    client_t *current = head;

    if (head == NULL)
        return NULL;
    while (strcmp(current->username, name) != 0) {
        if (current->next == NULL)
            return NULL;
        else
            current = current->next;
    }
    return current;
}
