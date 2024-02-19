/*
** EPITECH PROJECT, 2022
** myteams_cli
** File description:
** read_server_response.c
*/

#include "myteams_cli.h"
#include "logging_client.h"

void use_given_data(client_data_t *data, int cmd_index, int cmd_status)
{
    char **res_data = NULL;

    if (is_status_req_data(cmd_status) == 1)
        res_data = read_and_parse(data->c_socket);
    if (cmd_index < 14) {
        commands[cmd_index].func(res_data, cmd_status, data->command_send);
        if (res_data)
            free_word_array(res_data);
        return;
    }
    if (cmd_index == 30)
        message_event(res_data);
    else if (cmd_index == 100)
        client_error_unauthorized();
}

int get_response_code(char *line)
{
    char *first_bracket = strchr(line, '[');
    char *sec_bracket = strchr(line, ']');
    char code[5];
    int i = 0;

    if (!first_bracket || !sec_bracket)
        return -1;
    first_bracket++;
    while (i < 5 && first_bracket + i != sec_bracket) {
        code[i] = *(first_bracket + i);
        i++;
    }
    code[i] = '\0';
    return atoi(code);
}

void interpret_res_code(client_data_t *data, char *buf)
{
    int code = get_response_code(buf);
    int cmd_index = code / 100;
    int cmd_status = code % 100;

    if (code == -1)
        return;
    if ((cmd_index < 14 || cmd_index == 30)) {
        use_given_data(data, cmd_index, cmd_status);
        if (cmd_index == 2)
            data->exit = 1;
    }
}

int read_server_response(client_data_t *data)
{
    char *buf = my_read(data->c_socket);

    if (!buf)
        return -1;
    buf[strlen(buf) - 2] = '\0';
    printf("%s\r\n", buf);
    interpret_res_code(data, buf);
    if (data->command_send) {
        free_word_array(data->command_send);
        data->command_send = NULL;
    }
    free(buf);
    return 0;
}
