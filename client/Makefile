##
## EPITECH PROJECT, 2020
## myteams
## File description:
## MyTeams client Makefile
##

SRC		=	src/main.c											\
			src/myteams_cli.c									\
			src/utils/is_number.c								\
			src/utils/my_read.c									\
			src/utils/my_strtok.c								\
			src/utils/my_malloc.c								\
			src/utils/is_status_req_data.c						\
			src/connection/connect_to_server.c					\
			src/commands/commands_1.c							\
			src/commands/commands_2.c							\
			src/commands/commands_3.c							\
			src/events/message_event.c							\
			src/read_server_response/read_server_response.c		\
			src/free_data/free_data.c

OBJ		=	$(SRC:.c=.o)

NAME	=	myteams_cli

CFLAGS  +=	-W -Wall -Wextra -Iinclude -I../libs/myteams

LIBS	=	-L../libs/myteams -lmyteams

all: $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LIBS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f vgcore*

re:	clean all

debug: fclean
	gcc -g -o $(NAME) $(SRC) $(CFLAGS) $(LIBS)

valgrind: debug
	valgrind --leak-check=full --show-leak-kinds=all \
	--track-origins=yes ./$(NAME) 127.0.0.1 4242

.PHONY: all debug re clean fclean valgrind
