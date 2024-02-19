/*
** EPITECH PROJECT, 2022
** myteams_cli
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

void *my_realloc(void *ptr, size_t size)
{
    ptr = realloc(ptr, size);

    if (!ptr)
        exit(84);
    return ptr;
}
