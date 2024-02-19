/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** generate_uuid.c
*/
#include "myteams_server.h"
#include <stdlib.h>
#include <uuid/uuid.h>

char *generate_uuid(void)
{
    uuid_t binuuid;
    char *uuid = my_malloc(sizeof(char) * 37);

    if (!uuid)
        exit(84);
    uuid_generate_random(binuuid);
    uuid_unparse(binuuid, uuid);
    return uuid;
}
