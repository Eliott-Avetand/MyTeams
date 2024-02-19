/*
** EPITECH PROJECT, 2020
** myteams_cli
** File description:
** myteams_cli.h
*/

#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <stdarg.h>

#define UNUSED __attribute__((unused))

#define COMMAND_NUMBER 14
#define STATUS_REQ_DATA_NBR 6

typedef struct client_data_s client_data_t;
typedef struct commands_s commands_t;

struct client_data_s {
    int c_socket;
    fd_set read_fds;
    int exit;
    char **command_send;
};

// commands
void help_cmd(char **res_data, int status, char **cmd_send);
void login_cmd(char **res_data, int status, char **cmd_send);
void logout_cmd(char **res_data, int status, char **cmd_send);
void users_cmd(char **res_data, int status, char **cmd_send);
void user_cmd(char **res_data, int status, char **cmd_send);
void send_cmd(char **res_data, int status, char **cmd_send);
void messages_cmd(char **res_data, int status, char **cmd_send);
void subscribe_cmd(char **res_data, int status, char **cmd_send);
void subscribed_cmd(char **res_data, int status, char **cmd_send);
void unsubscribe_cmd(char **res_data, int status, char **cmd_send);
void use_cmd(char **res_data, int status, char **cmd_send);
void create_cmd(char **res_data, int status, char **cmd_send);
void list_cmd(char **res_data, int status, char **cmd_send);
void info_cmd(char **res_data, int status, char **cmd_send);

// events
void message_event(char **data);

struct commands_s {
    void (*func)(char **, int, char **);
};

static const commands_t commands[COMMAND_NUMBER] = {
    {help_cmd},
    {login_cmd},
    {logout_cmd},
    {users_cmd},
    {user_cmd},
    {send_cmd},
    {messages_cmd},
    {subscribe_cmd},
    {subscribed_cmd},
    {unsubscribe_cmd},
    {use_cmd},
    {create_cmd},
    {list_cmd},
    {info_cmd}
};

static const int status_req_data[STATUS_REQ_DATA_NBR] = {
    0, 11, 12, 13, 14, 15
};

// myteams_cli.c
int myteams_cli(char *ip, int port);

// connect_to_server.c
client_data_t *create_client_data(char *ip, int port);

// read_server_response.c
int read_server_response(client_data_t *data);

// free_data.c
void free_data(client_data_t *data);

// utils
bool is_number(char *str);
char *my_read(int fd);
char **my_strtok(char *str, char *delims);
char **read_and_parse(int c_socket);
void free_word_array(char **words);
int get_word_array_len(char **words);
void *my_malloc(int size);
void *my_realloc(void *ptr, size_t size);
int is_status_req_data(int status);
