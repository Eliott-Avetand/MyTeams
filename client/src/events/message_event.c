/*
** EPITECH PROJECT, 2022
** myteams_cli
** File description:
** message_event.c
*/

#include "myteams_cli.h"
#include "logging_client.h"

void message_event(char **res_data)
{
    char **user_data = my_strtok(res_data[0], "\x3\x4");

    client_event_private_message_received(user_data[0], user_data[1]);
    free_word_array(user_data);
}
