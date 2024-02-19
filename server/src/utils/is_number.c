/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** is_number.c
*/
#include <ctype.h>
#include <stdbool.h>

bool is_number(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}
