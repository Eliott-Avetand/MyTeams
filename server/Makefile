##
## EPITECH PROJECT, 2020
## myteams
## File description:
## Makefile
##

SRC	=	src/main.c							\
		src/errors/errors.c					\
		src/myteams_server.c				\
		src/processing.c					\
		src/utils/my_malloc.c				\
		src/utils/is_number.c				\
		src/utils/init_server.c				\
		src/utils/generate_uuid.c			\
		src/utils/my_str_to_word_array.c	\
		src/utils/double_array.c			\
		src/utils/are_quotes.c				\
		src/data/client.c					\
		src/data/client_utilities.c			\
		src/data/message.c					\
		src/data/message_utilities.c		\
		src/data/comment.c					\
		src/data/thread.c					\
		src/data/channel.c					\
		src/data/team_utilities.c			\
		src/data/team.c						\
		src/commands/help.c					\
		src/commands/login.c				\
		src/commands/logout.c				\
		src/commands/users.c				\
		src/commands/user.c					\
		src/commands/send.c					\
		src/commands/messages.c				\
		src/commands/subscribe.c			\
		src/commands/subscribed.c			\
		src/commands/unsubscribe.c			\
		src/commands/use.c					\
		src/commands/create.c				\
		src/commands/list.c					\
		src/commands/info.c					\
		src/commands/utilities.c

OBJ	=	$(SRC:.c=.o)

NAME	=	myteams_server

CFLAGS  +=      -W -Wall -Wextra -Iinclude -I../libs/myteams -luuid

LIBS	=	-L../libs/myteams -lmyteams

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f vgcore*

re:	clean all

debug:	fclean
	gcc -o $(NAME) $(SRC) $(CFLAGS) $(LIBS) -g

valgrind: debug
	valgrind --leak-check=full --show-leak-kinds=all \
	--track-origins=yes ./$(NAME) 4242

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LIBS)

.PHONY: all debug re clean fclean valgrind $(NAME)
