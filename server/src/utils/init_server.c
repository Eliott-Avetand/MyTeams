/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** init_server.c
*/
#include "myteams_server.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int create_socket(void)
{
    int sfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sfd == -1) {
        dprintf(1, "Socket creation failed...\r\n");
        exit(84);
    }
    return sfd;
}

void configure_socket(int sfd, int port)
{
    struct sockaddr_in server;

    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    if (bind(sfd, (struct sockaddr *)&server, sizeof(server)) == -1) {
        dprintf(1, "Socket bind failed...\r\n");
        exit(84);
    }
    if (listen(sfd, 50) == -1) {
        dprintf(1, "Listen failed...\r\n");
        exit(84);
    }
}

server_t *init_server(int port)
{
    server_t *server = my_malloc(sizeof(server_t));

    server->fd = create_socket();
    server->teams = NULL;
    server->clients = NULL;
    configure_socket(server->fd, port);
    return server;
}
