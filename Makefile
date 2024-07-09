# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/09 16:21:28 by rbuitrag          #+#    #+#              #
#    Updated: 2024/07/09 16:45:47 by rbuitrag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = program
SERVER = server
CLIENT = client
CC = gcc
LIB = ./utils.c

CFLAGS = -Wall -Werror -Wextra -fsanitize=leak

all: $(SERVER) $(CLIENT)

$(NAME): all

$(SERVER):
	$(CC) $(CFLAGS) server.c $(LIB) -o $(SERVER)

$(CLIENT):
	$(CC) $(CFLAGS) client.c $(LIB) -o $(CLIENT)

clean:
	rm -rf $(SERVER) $(CLIENT)

fclean: clean

re: fclean all

.PHONY: all flean clean re
