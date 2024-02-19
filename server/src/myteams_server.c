/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** myteams_server.c
*/
#include "myteams_server.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <arpa/inet.h>
#include <errno.h>

void handle_client(server_t *server, int fd)
{
    char *buf = my_malloc(sizeof(char) * 4096);
    int nbytes = read(fd, buf, 4096);
    client_t *client = find_client_by_fd(server->clients, fd);

    if (nbytes <= 1) {
        shutdown(client->fd, SHUT_RDWR);
        close(client->fd);
        FD_CLR(client->fd, &server->main_set);
        delete_client(&server->clients, client->uuid);
    } else {
        buf[nbytes] = '\0';
        middleware(buf, client, server);
    }
}

void handle_server(server_t *server)
{
    int afd;
    struct sockaddr_in client;
    socklen_t len = sizeof(struct sockaddr_in);

    if ((afd = accept(server->fd, (struct sockaddr *)&client, &len)) == -1)
        dprintf(0, "An error occurs...\r\n");
    else {
        FD_SET(afd, &server->main_set);
        add_client(&server->clients, afd);
        if (afd > server->nfds)
            server->nfds = afd;
        dprintf(afd, "[2000] Service ready for new user.\r\n\x4");
    }
}

void handle_fds(server_t *server)
{
    for (int i = 0; i < server->nfds + 1; i++) {
        if (FD_ISSET(i, &server->tmp_set) && i == server->fd)
            handle_server(server);
        else if (FD_ISSET(i, &server->tmp_set))
            handle_client(server, i);
    }
}

int software_loop(server_t *server)
{
    FD_ZERO(&server->main_set);
    FD_ZERO(&server->tmp_set);
    FD_SET(server->fd, &server->main_set);
    server->nfds = server->fd;
    while (1) {
        memcpy(&server->tmp_set, &server->main_set, sizeof(server->main_set));
        if (select(server->nfds + 1, &server->tmp_set, NULL, NULL, NULL) == -1)
            exit(84);
        handle_fds(server);
    }
}

int myteams_server(int port)
{
    server_t *server = init_server(port);

    software_loop(server);
    return 0;
}
