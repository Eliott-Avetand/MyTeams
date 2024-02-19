/*
** EPITECH PROJECT, 2022
** myteams_cli
** File description:
** commands_2.c
*/

#include "myteams_cli.h"
#include "logging_client.h"

void send_cmd(char **res_data, int status, UNUSED char **cmd_send)
{
    char **user_data = NULL;

    if (status == 11) {
        user_data = my_strtok(res_data[0], "\x3\x4");
        client_error_unknown_user(user_data[0]);
    }
}

void messages_cmd(char **res_data, int status, UNUSED char **cmd_send)
{
    char **user_data = NULL;

    if (status == 11) {
        user_data = my_strtok(res_data[0], "\x3\x4");
        client_error_unknown_user(user_data[0]);
        return free_word_array(user_data);
    } else if (status != 0)
        return;
    for (int i = 0; res_data[i]; i++) {
        user_data = my_strtok(res_data[i], "\x3\x4");
        client_private_message_print_messages(user_data[0],
        atol(user_data[1]), user_data[2]);
        free_word_array(user_data);
    }
}

void subscribe_cmd(char **res_data, int status, UNUSED char **cmd_send)
{
    char **user_data = NULL;

    if (status != 0 && status != 11 && status != 12)
        return;
    user_data = my_strtok(res_data[0], "\x3\x4");
    if (status == 11)
        client_error_unknown_user(user_data[0]);
    else if (status == 12)
        client_error_unknown_team(user_data[0]);
    else
        client_print_subscribed(user_data[0], user_data[1]);
    free_word_array(user_data);
}

void subscribed_cmd(char **res_data, int status, char **cmd_send)
{
    char **user_data = NULL;

    if ((status != 0 && status != 12) || !cmd_send)
        return;
    user_data = my_strtok(res_data[0], "\x3\x4");
    if (status == 12)
        client_error_unknown_team(user_data[0]);
    else if (get_word_array_len(cmd_send) == 1)
        client_print_teams(user_data[0], user_data[1], user_data[2]);
    else
        client_print_users(user_data[0], user_data[1], atoi(user_data[2]));
    free_word_array(user_data);
}

void unsubscribe_cmd(char **res_data, int status, UNUSED char **cmd_send)
{
    char **user_data = NULL;

    if ((status != 0 && status != 12) || !cmd_send)
        return;
    user_data = my_strtok(res_data[0], "\x3\x4");
    if (status == 12)
        client_error_unknown_team(user_data[0]);
    else
        client_print_unsubscribed(user_data[0], user_data[1]);
    free_word_array(user_data);
}
