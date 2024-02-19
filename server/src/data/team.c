/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** team.c
*/
#include "myteams_server.h"
#include <string.h>
#include <stdlib.h>

bool is_empty_team(team_t *head)
{
    return head == NULL;
}

void delete_team(team_t **head, char *uuid)
{
    team_t *current = *head;
    team_t *tmp = NULL;

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
    delete_all_channels(&tmp->channels);
    free(tmp->uuid);
    free(tmp);
}

void delete_all_teams(team_t **head)
{
    team_t *current = *head;
    team_t *tmp = current;

    if (current == NULL)
        return;
    while (current->next != NULL) {
        tmp = current;
        current = current->next;
        delete_all_channels(&current->channels);
        free(tmp->uuid);
        free(tmp);
    }
    delete_all_channels(&current->channels);
    free(current->uuid);
    free(current);
}

team_t *find_team(team_t *head, char *uuid)
{
    team_t *current = head;

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

void add_team(team_t **head, char *name, char *desc, char *uuid)
{
    team_t *current = (*head);
    team_t *team = my_malloc(sizeof(team_t));

    team->uuid = strdup(uuid);
    team->name = strdup(name);
    team->desc = strdup(desc);
    team->next = NULL;
    team->subscribed_user = NULL;
    team->channels = NULL;
    if ((*head) == NULL)
        (*head) = team;
    else {
        while (current->next != NULL)
            current = current->next;
        current->next = team;
    }
}
