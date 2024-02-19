/*
** EPITECH PROJECT, 2022
** myteams_cli
** File description:
** myteams_cli.c
*/

#include "myteams_cli.h"

char **command_to_word_array(char *buf)
{
    char *n_str = my_malloc(sizeof(char) * (strlen(buf) + 1));
    char **words = NULL;
    int counter = 0;

    for (int i = 0; buf[i]; i++) {
        if (buf[i] != '\"') {
            n_str[counter] = buf[i];
            counter++;
        }
    }
    n_str[counter] = '\0';
    words = my_strtok(n_str, " \t\r\n\x4");
    free(n_str);
    return words;
}

int send_to_server(client_data_t *data)
{
    char *buf = NULL;
    size_t readlen = 256;
    ssize_t len = getline(&buf, &readlen, stdin);

    if (len < 0)
        return -1;
    buf[len - 1] = '\0';
    dprintf(data->c_socket, "%s\r\n\x4", buf);
    data->command_send = command_to_word_array(buf);
    free(buf);
    return 0;
}

void client_loop(client_data_t *data)
{
    fd_set read_tmp = data->read_fds;

    if (data->exit == 1)
        return;
    if (select(data->c_socket + 1, &read_tmp, NULL, NULL, NULL) == -1)
        exit(84);
    if (FD_ISSET(STDIN_FILENO, &read_tmp)) {
        if (send_to_server(data) == -1)
            exit(84);
    } else if (FD_ISSET(data->c_socket, &read_tmp)) {
        if (read_server_response(data) == -1)
            exit(84);
    }
    FD_ZERO(&read_tmp);
}

int myteams_cli(char *ip, int port)
{
    client_data_t *data = create_client_data(ip, port);

    if (!data)
        return 84;
    while (data->exit == 0)
        client_loop(data);
    free_data(data);
    return 0;
}
