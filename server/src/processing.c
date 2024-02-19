/*
** EPITECH PROJECT, 2020
** myftp
** File description:
** processing.c
*/
#include "myteams_server.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int handle_args(char **words)
{
    int counter = 0;
    int arg_index = 1;
    int char_index = 0;

    while (words[arg_index]) {
        if (words[arg_index][char_index] == '"') {
            counter++;
            char_index++;
        } else if (words[arg_index][char_index] == '\0') {
            char_index = 0;
            arg_index++;
        } else
            char_index++;
        if (counter != 2 && char_index == 0)
            return -1;
        else if (counter == 2 && char_index == 0)
            counter = 0;
    }
    return 0;
}

void handle_commands(char **words, client_t *client, server_t *server)
{
    int counter = 0;

    if (!client->is_connected && strcmp(words[0], "/help") != 0
    && strcmp(words[0], "/login") != 0) {
        dprintf(client->fd, "[10000] Please login.\r\n\x4");
        return;
    }
    usleep(5000);
    for (; counter < COMMAND_NUMBER; counter++) {
        if (strcmp(words[0], commands_s[counter].name) == 0) {
            (commands_s[counter].func)(server, client, words);
            break;
        }
    }
    if (counter == COMMAND_NUMBER)
        dprintf(client->fd, "[5000] Command not implemented.\r\n\x4");
}

void middleware(char *input, client_t *client, server_t *server)
{
    char **words = NULL;
    char *new_str = are_quotes(input);

    if (new_str != NULL) {
        words = my_str_to_word_array(new_str);
        handle_commands(words, client, server);
    } else
        dprintf(client->fd, "[5000] '\"' misses.\r\n\x4");
}
