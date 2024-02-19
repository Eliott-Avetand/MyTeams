/*
** EPITECH PROJECT, 2022
** myteams_cli
** File description:
** main.c
*/

#include "myteams_cli.h"

int check_help(char *arg)
{
    if (strcmp(arg, "-help") != 0 && strcmp(arg, "-h") != 0) {
        printf("ERROR: Invalid args numbers"
        " (-help for further informations).\n");
        return 84;
    }
    printf("USAGE: ./myteams_cli ip port\n");
    printf("\tip"
    "\tis the server ip address on which the server socket listens\n");
    printf("\tport"
    "\tis the port number on which the server socket listens\n");
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 2)
        return check_help(av[1]);
    else if (ac == 3) {
        if (is_number(av[2]) == false) {
            printf("ERROR: The port must be an int.\n");
            return 84;
        }
        return myteams_cli(av[1], atoi(av[2]));
    } else {
        printf("ERROR: Invalid args numbers"
        " (-help for further informations).\n");
        return 84;
    }
}
