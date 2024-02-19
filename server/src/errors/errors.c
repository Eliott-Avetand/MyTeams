/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** errors.c
*/
#include "myteams_server.h"
#include <stdio.h>
#include <stdlib.h>

int handle_errors(char *port)
{
    if (is_number(port)) {
        myteams_server(atoi(port));
        return 0;
    } else {
        printf("ERROR: The port must be an int.\r\n");
        return 84;
    }
}
