/*
** EPITECH PROJECT, 2022
** myteams_cli
** File description:
** int_array_contains.c
*/

#include "myteams_cli.h"

int is_status_req_data(int status)
{
    for (int i = 0; i < STATUS_REQ_DATA_NBR; i++) {
        if (status == status_req_data[i])
            return 1;
    }
    return 0;
}
