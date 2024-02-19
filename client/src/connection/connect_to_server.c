/*
** EPITECH PROJECT, 2022
** myteams_cli
** File description:
** connect_to_server.c
*/

#include "myteams_cli.h"

int create_client_socket(char *ip, int port)
{
    int c_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in sc_addr;

    if (c_socket == -1)
        return -1;
    sc_addr.sin_family = AF_INET;
    sc_addr.sin_port = htons(port);
    sc_addr.sin_addr.s_addr = inet_addr(ip);
    if (connect(c_socket, (struct sockaddr *)&sc_addr, sizeof(sc_addr)) != 0) {
        close(c_socket);
        return -1;
    }
    return c_socket;
}

client_data_t *create_client_data(char *ip, int port)
{
    client_data_t *data = my_malloc(sizeof(client_data_t));

    data->c_socket = create_client_socket(ip, port);
    if (data->c_socket == -1)
        return NULL;
    data->exit = 0;
    data->command_send = NULL;
    FD_ZERO(&data->read_fds);
    FD_SET(STDIN_FILENO, &data->read_fds);
    FD_SET(data->c_socket, &data->read_fds);
    if (fcntl(data->c_socket, F_SETFL,
    fcntl(data->c_socket, F_GETFL, 0) | O_NONBLOCK) == -1)
        return NULL;
    return data;
}
