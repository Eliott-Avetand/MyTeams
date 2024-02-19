/*
** EPITECH PROJECT, 2022
** myteams_cli
** File description:
** free_data.c
*/

#include "myteams_cli.h"

void free_data(client_data_t *data)
{
    FD_ZERO(&data->read_fds);
    close(data->c_socket);
    if (data->command_send)
        free_word_array(data->command_send);
    free(data);
}
