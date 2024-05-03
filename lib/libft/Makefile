# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 14:41:26 by bapasqui          #+#    #+#              #
#    Updated: 2024/04/17 15:46:28 by bapasqui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a


SRCS =		ft_isalpha.c	\
			ft_isdigit.c	\
			ft_isalnum.c	\
			ft_isascii.c	\
			ft_isprint.c	\
			ft_strlen.c		\
			ft_memset.c		\
			ft_bzero.c		\
			ft_memcpy.c		\
			ft_memmove.c	\
			ft_strlcpy.c	\
			ft_strlcat.c	\
			ft_toupper.c	\
			ft_tolower.c	\
			ft_strchr.c		\
			ft_strrchr.c	\
			ft_strncmp.c	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_strnstr.c	\
			ft_atoi.c		\
			ft_calloc.c		\
			ft_strdup.c		\
			ft_substr.c		\
			ft_strjoin.c	\
			ft_strtrim.c	\
			ft_split.c		\
			ft_itoa.c		\
			ft_strmapi.c	\
			ft_striteri.c	\
			ft_putchar_fd.c	\
			ft_putstr_fd.c	\
			ft_putendl_fd.c	\
			ft_strcpy.c		\
			ft_free.c \
			get_next_line.c	\
			get_next_line_utils.c	\
			ft_putnbr_fd.c


all: $(NAME)

$(NAME): ft_printf $(OBJS)
	echo "Compiling\033[1m\033[32m libft \033[0m"
	ar rc $(NAME) $(OBJS)

ft_printf:
	@make -C ../ft_printf
	@mv ../ft_printf/libftprintf.a $(NAME)

clean:
	@make -C ../ft_printf clean
	rm -rf $(OBJS)

fclean: clean
	@make -C ../ft_printf fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re ft_printf
