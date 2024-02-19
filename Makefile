##
## EPITECH PROJECT, 2020
## myteams
## File description:
## Makefile
##

BIN_SERVER	=	myteams_server
BIN_CLIENT	=	myteams_cli

all: build_client build_server

build_client:
	$(MAKE) -C client
	mv client/$(BIN_CLIENT) .

build_server:
	$(MAKE) -C server
	mv server/$(BIN_SERVER) .

clean:
	$(MAKE) clean -C client
	$(MAKE) clean -C server

fclean:	clean
	$(MAKE) fclean -C client
	$(MAKE) fclean -C server
	rm -rf $(BIN_CLIENT)
	rm -rf $(BIN_SERVER)

re:	clean all

debug:	fclean
	$(MAKE) debug -C client
	$(MAKE) debug -C server

valgrind: debug
	$(MAKE) valgrind -C client
	$(MAKE) valgrind -C server

.PHONY: all build_client build_server debug re clean fclean valgrind
