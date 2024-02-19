/*
** EPITECH PROJECT, 2022
** myteams_cli
** File description:
** my_strtok.c
*/

#include "myteams_cli.h"

int get_word_array_len(char **words)
{
    int counter = 0;

    while (words[counter] != NULL)
        counter++;
    return counter;
}

void free_word_array(char **words)
{
    for (int i = 0; words[i]; i++)
        free(words[i]);
    free(words);
}

int separate_token(char ***words, char *n_str, char *delims)
{
    char *token;
    int arr_len = 0;

    token = strtok(n_str, delims);
    while (token != NULL) {
        (*words) = my_realloc((*words), sizeof(char *) * (arr_len + 2));
        (*words)[arr_len] = strdup(token);
        if (!(*words)[arr_len])
            return -1;
        token = strtok(NULL, delims);
        arr_len++;
    }
    (*words)[arr_len] = NULL;
    return 0;
}

char **my_strtok(char *str, char *delims)
{
    char *n_str = strdup(str);
    char **words = malloc(sizeof(char *));

    if (!n_str || !words)
        return NULL;
    if (separate_token(&words, n_str, delims) == -1)
        return NULL;
    free(n_str);
    return words;
}
