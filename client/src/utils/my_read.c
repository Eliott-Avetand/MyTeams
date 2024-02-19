/*
** EPITECH PROJECT, 2022
** myteams_cli
** File description:
** my_read.c
*/

#include "myteams_cli.h"

char **read_and_parse(int c_socket)
{
    char *buf = my_read(c_socket);
    char **words = NULL;

    if (!buf)
        return NULL;
    words = my_strtok(buf, "\r\n\x4");
    free(buf);
    return words;
}

char *my_read(int fd)
{
    char *buf = my_malloc(sizeof(char) * 257);
    ssize_t read_ret = 1;
    ssize_t buf_len = 0;

    if (!buf)
        return NULL;
    while (read_ret > 0) {
        read_ret = read(fd, buf + buf_len, 1);
        buf_len += 1;
        if (buf[buf_len - 1] == 4)
            break;
        if (buf_len % 256 == 0)
            buf = my_realloc(buf, buf_len * 2);
        if (!buf)
            return NULL;
    }
    if (read_ret < 1)
        exit(0);
    buf[buf_len - 1] = '\0';
    return buf;
}
