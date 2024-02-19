/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** main.c
*/
#include "myteams_server.h"
#include <string.h>
#include <stdio.h>

int check_help(char *arg)
{
    if (strcmp(arg, "-help") == 0) {
        printf("USAGE: ./myteams_server port\n\n");
        printf("\tport"
        "\tis the port number on which the server socket listens\n");
        return 0;
    } else
        return handle_errors(arg);
}

int main(int ac, char **av)
{
    if (ac == 2)
        return check_help(av[1]);
    else {
        printf("ERROR: Invalid args numbers"
        " (-help for further informations).\n");
        return 84;
    }
}
