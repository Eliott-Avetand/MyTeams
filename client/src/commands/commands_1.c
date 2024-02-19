/*
** EPITECH PROJECT, 2022
** myteams_cli
** File description:
** commands_1.c
*/

#include "myteams_cli.h"
#include "logging_client.h"

void help_cmd(char **res_data, int status, UNUSED char **cmd_send)
{
    if (status != 0)
        return;
    for (int i = 0; res_data[i]; i++)
        printf("%s\n", res_data[i]);
}

void login_cmd(char **res_data, int status, UNUSED char **cmd_send)
{
    char **user_data = NULL;

    if (status != 0)
        return;
    user_data = my_strtok(res_data[0], "\x3\x4");
    client_event_logged_in(user_data[0], user_data[1]);
    free_word_array(user_data);
}

void logout_cmd(char **res_data, int status, UNUSED char **cmd_send)
{
    char **user_data = NULL;

    if (status != 0)
        return;
    user_data = my_strtok(res_data[0], "\x3\x4");
    client_event_logged_out(user_data[0], user_data[1]);
    free_word_array(user_data);
}

void users_cmd(char **res_data, int status, UNUSED char **cmd_send)
{
    char **user_data = NULL;

    if (status != 0)
        return;
    for (int i = 0; res_data[i]; i++) {
        user_data = my_strtok(res_data[i], "\x3\x4");
        client_print_users(user_data[0], user_data[1], atoi(user_data[2]));
        free_word_array(user_data);
    }
}

void user_cmd(char **res_data, int status, UNUSED char **cmd_send)
{
    char **user_data = NULL;

    if (status != 0 && status != 11)
        return;
    user_data = my_strtok(res_data[0], "\x3\x4");
    if (status == 0)
        client_print_user(user_data[0], user_data[1], atoi(user_data[2]));
    else if (status == 11)
        client_error_unknown_user(user_data[0]);
    free_word_array(user_data);
}
