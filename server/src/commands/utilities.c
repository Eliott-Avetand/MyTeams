/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** utilities.c
*/
#include "myteams_server.h"
#include <stdio.h>

bool check_commands_args(int nb, char **args)
{
    int count_words = double_array_len(args);

    if (count_words != nb)
        return false;
    return true;
}
