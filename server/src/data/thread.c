/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** thread.c
*/
#include "myteams_server.h"
#include <string.h>
#include <stdlib.h>

bool is_empty_thead(thread_t *head)
{
    return head == NULL;
}

void delete_thread(thread_t **head, char *uuid)
{
    thread_t *current = *head;
    thread_t *tmp = NULL;

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
    delete_all_comments(&tmp->comment);
    free(tmp->uuid);
    free(tmp);
}

void delete_all_threads(thread_t **head)
{
    thread_t *current = *head;
    thread_t *tmp = current;

    if (current == NULL)
        return;
    while (current->next != NULL) {
        tmp = current;
        current = current->next;
        delete_all_comments(&current->comment);
        free(tmp->uuid);
        free(tmp);
    }
    delete_all_comments(&current->comment);
    free(current->uuid);
    free(current);
}

thread_t *find_thead(thread_t *head, char *uuid)
{
    thread_t *current = head;

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

void add_thread(thread_t **head, char *uuid)
{
    thread_t *current = (*head);
    thread_t *thread = my_malloc(sizeof(thread_t));

    thread->uuid = uuid;
    thread->next = NULL;
    if ((*head) == NULL)
        (*head) = thread;
    else {
        while (current->next != NULL)
            current = current->next;
        current->next = thread;
    }
}
