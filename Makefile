# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 10:49:06 by bapasqui          #+#    #+#              #
#    Updated: 2024/06/05 23:07:41 by baptiste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef VERBOSE
MAKEFLAGS += --no-print-directory --silent
endif

MAKEFLAGS += -j

# Makefile vars
CC := clang                                                       
NAME    := cube3d
CFLAGS  := -Wextra -Wall -Werror -g -O3 -ffast-math #-fsanitize=address -fsanitize=undefined
SRCS    := src/main.c \
           src/event.c \
		   src/movement_utils.c \
           src/init_mlx.c \
           src/render_wall.c \
           src/render_map.c \
           src/movement.c \
           src/free.c \
		   src/lst_print.c \
		   src/parser.c \
		   src/ray_handle.c \
		   src/error.c \


OBJS_DIR := obj
OBJS    := $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))
LIBS    := -L ./minilibx -lmlx -lXext -lX11 -lm -lbsd

all: $(NAME)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@make -C minilibx
	@make -C lib
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) lib/libft.a
	echo "Compiling\033[1m\033[32m" $@ "\033[0m"
	echo "\033[42mSuccessfully compiled :)\033[0m"


lib:
	@if [ ! -d "minilibx" ]; then wget https://cdn.intra.42.fr/document/document/22379/minilibx-linux.tgz && tar -xvf minilibx-linux.tgz && rm -f minilibx-linux.tgz && mv minilibx-linux minilibx; fi
	@if [ -d "minilibx/.git" ]; then rm -rf minilibx/.git; fi
	
norm:
	@-norminette src/ includes/ lib/

clean:
	@make -C lib clean
	@rm -rf $(OBJS_DIR)

fclean: clean
	@make fclean -C lib
	@rm -rf $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) -j$(nproc)

.PHONY: all clean fclean re gt