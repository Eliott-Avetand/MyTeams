/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** comment.c
*/
#include "myteams_server.h"
#include <string.h>
#include <stdlib.h>

bool is_empty_comment(comment_t *head)
{
    return head == NULL;
}

void delete_comment(comment_t **head, char *uuid)
{
    comment_t *current = *head;
    comment_t *tmp = NULL;

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

void delete_all_comments(comment_t **head)
{
    comment_t *current = *head;
    comment_t *tmp = current;

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

comment_t *find_comment(comment_t *head, char *uuid)
{
    comment_t *current = head;

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

void add_comment(comment_t **head, char *uuid)
{
    comment_t *current = (*head);
    comment_t *comment = my_malloc(sizeof(comment_t));

    comment->uuid = uuid;
    comment->next = NULL;
    if ((*head) == NULL)
        (*head) = comment;
    else {
        while (current->next != NULL)
            current = current->next;
        current->next = comment;
    }
}
