/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** myteams_server.h
*/
#pragma once

#include "logging_server.h"
#include <stdbool.h>
#include <uuid/uuid.h>

#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH 512
#define COMMAND_NUMBER 10

typedef struct message_s {
    char *uuid;
    char message_body[MAX_BODY_LENGTH];
    char *recipient_uuid;
    char *author_uuid;
    time_t timestamp;
    struct message_s *next;
} message_t;

bool is_empty_message(message_t *head);
void add_message(message_t **head, message_t *message);
void delete_message(message_t **head, char *uuid);
void delete_all_messages(message_t **head);
message_t *find_message(message_t *head, char *uuid);
message_t *create_message(char *author_uuid,
char *recipient_uuid, char *message_body);

typedef struct subscription_s {
    char *subscription_uuid;
    char *subscription_name;
    struct subscription_s *next;
} subscription_t;

// data's linked lists
typedef struct client_s {
    int fd;
    char *uuid;
    char *username;
    char *context;
    int is_connected;
    message_t *messages;
    subscription_t *subscribed_team;
    struct client_s *next;
} client_t;

bool is_empty_client(client_t *head);
client_t *find_client_by_fd(client_t *head, int fd);
client_t *find_client_by_uuid(client_t *head, char *fd);
void delete_client(client_t **head, char *uuid);
void delete_all_clients(client_t **head);
void add_client(client_t **head, int fd);
client_t *find_client_by_name(client_t *head, char *name);

typedef struct comment_s {
    char *uuid;
    char message_body[MAX_BODY_LENGTH];
    char *recipient_uuid;
    struct comment_s *next;
} comment_t;

bool is_empty_comment(comment_t *head);
void add_comment(comment_t **head, char *uuid);
void delete_comment(comment_t **head, char *uuid);
void delete_all_comments(comment_t **head);
comment_t *find_comment(comment_t *head, char *uuid);

typedef struct thread_s {
    char *uuid;
    message_t *post;
    comment_t *comment;
    client_t *author;
    struct thread_s *next;
} thread_t;

bool is_empty_thread(thread_t *head);
void add_thread(thread_t **head, char *uuid);
void delete_thread(thread_t **head, char *uuid);
void delete_all_threads(thread_t **head);
thread_t *find_thread(thread_t *head, char *uuid);

typedef struct channel_s {
    char *uuid;
    thread_t *threads;
    struct channel_s *next;
} channel_t;

bool is_empty_channel(channel_t *head);
void add_channel(channel_t **head, char *uuid);
void delete_channel(channel_t **head, char *uuid);
void delete_all_channels(channel_t **head);
channel_t *find_channel(channel_t *head, char *uuid);

typedef struct team_s {
    char *uuid;
    char *name;
    char *desc;
    subscription_t *subscribed_user;
    channel_t *channels;
    struct team_s *next;
} team_t;

bool is_empty_team(team_t *head);
void add_team(team_t **head, char *name, char *desc, char *uuid);
void delete_team(team_t **head, char *uuid);
void delete_all_teams(team_t **head);
team_t *find_team(team_t *head, char *uuid);

// server's structure
typedef struct server_s {
    int fd;
    int nfds;
    fd_set main_set;
    fd_set tmp_set;
    team_t *teams;
    client_t *clients;
} server_t;

server_t *init_server(int port);

// Commands handler
void help(server_t *server, client_t *client, char **args);
void login(server_t *server, client_t *client, char **args);
void logout(server_t *server, client_t *client, char **args);
void users(server_t *server, client_t *client, char **args);
void user(server_t *server, client_t *client, char **args);
void send_message(server_t *server, client_t *client, char **args);
void messages(server_t *server, client_t *client, char **args);
void subscribe(server_t *server, client_t *client, char **args);
void subscribed(server_t *server, client_t *client, char **args);
void unsubscribe(server_t *server, client_t *client, char **args);
void use(server_t *server, client_t *client, char **args);
void create(server_t *server, client_t *client, char **args);
void list(client_t *client, char **args);
void info(client_t *client, char **args);

void add_client_subscription(client_t *client, char *name, char *uuid);
void add_team_subscription(team_t *client, char *name, char *uuid);
void delete_subscription(subscription_t **head, char *uuid);

typedef struct func_s {
    char *name;
    void (*func)(server_t *server, client_t *, char **);
} func_t;

static const func_t commands_s[COMMAND_NUMBER] = {
    {"/help", help},
    {"/login", login},
    {"/logout", logout},
    {"/users", users},
    {"/user", user},
    {"/send", send_message},
    {"/messages", messages},
    {"/subscribe", subscribe},
    {"/subscribed", subscribed},
    {"/unsubscribe", unsubscribe},
};

// errors
int handle_errors(char *port);

// utils functions
void *my_malloc(int size);
bool is_number(char *str);
char *generate_uuid(void);
char **my_str_to_word_array(char *str);
int double_array_len(char **array);
void free_double_array(char **array);
bool check_commands_args(int nb, char **args);
char *are_quotes(char *str);

// main functions
int myteams_server(int port);
void middleware(char *input, client_t *client, server_t *server);
