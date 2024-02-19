/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** team_utilities.c
*/
#include "myteams_server.h"
#include <string.h>
#include <stdlib.h>

void add_team_subscription(team_t *team, char *name, char *uuid)
{
    subscription_t **current = &team->subscribed_user;
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
