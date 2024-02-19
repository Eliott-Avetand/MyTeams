/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** my_malloc.c
*/

#include <stdlib.h>

void *my_malloc(int size)
{
    void *value = malloc(size);

    if (!value)
        exit(84);
    return value;
}
