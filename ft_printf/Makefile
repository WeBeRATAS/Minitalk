# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbuitrag <rbuitrag@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 12:09:04 by rbuitrag          #+#    #+#              #
#    Updated: 2024/03/25 17:29:18 by rbuitrag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

HEADER = ft_printf.h

FLAGS = -Wall -Werror -Wextra -c

FILES = ft_printf.c p_digit.c print_str.c print_char.c print_pointer.c \
		p_hexa.c

OFILES = $(FILES:.c=.o)

all : $(NAME)

$(NAME) : $(OFILES)
	ar rc $(NAME) $(OFILES)

%.o:%.c $(HEADER) Makefile
	$(CC) $(FLAGS) $<

clean:
	rm -f $(OFILES)

fclean : clean
	rm -f $(NAME) $(OFILES) a.out

re : fclean all

.PHONY: clean fclean all re
