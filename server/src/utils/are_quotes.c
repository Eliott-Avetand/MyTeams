/*
** EPITECH PROJECT, 2020
** myftp
** File description:
** are_quotes.c
*/
#include "myteams_server.h"
#include <stdlib.h>
#include <string.h>

char *are_quotes(char *str)
{
    char *n_str = my_malloc(sizeof(char) * (strlen(str) + 1));
    int counter = 0;
    int nb_quotes = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] != '\"') {
            n_str[counter] = str[i];
            counter++;
        } else if (str[i] == '\"')
            nb_quotes++;
    }
    if (nb_quotes % 2 != 0)
        return NULL;
    n_str[counter] = '\0';
    return n_str;
}
