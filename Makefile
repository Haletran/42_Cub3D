# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 10:49:06 by bapasqui          #+#    #+#              #
#    Updated: 2024/08/18 23:14:55 by bapasqui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef VERBOSE
MAKEFLAGS += --no-print-directory --silent
endif

MAKEFLAGS += -j

# Makefile vars
CC := clang                                                             
NAME    := cub3D
CFLAGS  := -Wextra -Wall -Werror -g#-fsanitize=address
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
		   src/utils.c \
		   src/flood_fill.c \
		   src/minimap.c \
		   src/draw.c \
		   src/utils_parsing.c \
		   src/init_struct.c \
		   src/weapon.c \
		   src/mouse_event.c \
		   src/data_checker.c \


OBJS_DIR := obj
OBJS    := $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))
LIBS    := MacroLibX/libmlx.so -lSDL2 -lm

all: $(NAME)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@make -C MacroLibX
	@make -C lib
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) lib/libft.a $(LIBS)
	echo "Compiling\033[1m\033[32m" $@ "\033[0m"
	echo "\033[42mSuccessfully compiled :)\033[0m"

norm:
	@clear
	@echo "\033[1m\033[32m""[ Norminette ]" "\033[0m"
	-@norminette $(SRCS) lib/ includes/

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --suppressions=MacroLibX/valgrind.supp ./$(NAME) maps/map_sujet.cub

macro:
	@if [ ! -d MacroLibX ]; then git clone https://github.com/seekrs/MacroLibX.git; else echo "\033[31m""MacroLibX already installed" "\033[0m"; fi
	@make -C MacroLibX

clean:
	@make -C lib clean
	@make -C MacroLibX clean
	@rm -rf $(OBJS_DIR)

fclean: clean
	@make fclean -C lib
	@make fclean -C MacroLibX
	@rm -rf $(NAME)

fclean_macro: clean
	@make fclean -C lib
	@make fclean -C MacroLibX
	@rm -rf $(NAME)
	@rm -rf MacroLibX

re:
	$(MAKE) fclean
	$(MAKE) -j$(nproc)

.PHONY: all clean fclean re gt
