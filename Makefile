# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboukent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 09:58:08 by aboukent          #+#    #+#              #
#    Updated: 2024/11/27 10:04:18 by aboukent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_putnbr_u.c ft_hexadecimal.c ft_address.c

OBJ = ${SRC:.c=.o}

NAME = libftprintf.a

${NAME}: ${OBJ}
	ar rcs ${NAME} ${OBJ}
all: ${NAME}

%.o: %.c
	cc -c -Wall -Werror -Wextra ${SRC}
clean:
	rm -f ${OBJ}
fclean: clean
	rm -f ${NAME}
re: fclean all

.PHONY: all clean fclean re