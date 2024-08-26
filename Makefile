# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bapt <bapt@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 10:49:06 by bapasqui          #+#    #+#              #
#    Updated: 2024/08/26 12:55:11 by bapt             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef VERBOSE
MAKEFLAGS += --no-print-directory --silent
endif

MAKEFLAGS += -j

# Makefile vars
CC := clang                                                             
NAME    := cub3D
NAME_BONUS := cub3D_bonus
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
		   src/draw.c \
		   src/utils_parsing.c \
		   src/init_struct.c \
		   src/data_checker.c \

SRCS_BONUS := src_bonus/data_checker_bonus.c \
		   src_bonus/draw_bonus.c \
		   src_bonus/error_bonus.c \
		   src_bonus/event_bonus.c \
		   src_bonus/flood_fill_bonus.c \
		   src_bonus/free_bonus.c \
		   src_bonus/init_mlx_bonus.c \
		   src_bonus/init_struct_bonus.c \
		   src_bonus/lst_print_bonus.c \
		   src_bonus/main_bonus.c \
		   src_bonus/minimap_bonus.c \
		   src_bonus/mouse_event_bonus.c \
		   src_bonus/movement_bonus.c \
		   src_bonus/movement_utils_bonus.c \
		   src_bonus/parser_bonus.c \
		   src_bonus/ray_handle_bonus.c \
		   src_bonus/render_map_bonus.c \
		   src_bonus/render_wall_bonus.c \
		   src_bonus/utils_bonus.c \
		   src_bonus/utils_parsing_bonus.c \
		   src_bonus/weapon_bonus.c \

OBJS_DIR := obj
OBJS    := $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))
OBJS_BONUS := $(addprefix $(OBJS_DIR)/,$(SRCS_BONUS:.c=.o))
LIBS    := MacroLibX/libmlx.so -lSDL2 -lm

all: $(NAME)

$(OBJS_DIR)/%.o: %.c
	@clear
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@echo "\033[1m\033[32m""[ Cub3D ]" "\033[0m"
	@echo "Compiling\033[1m\033[32m" MacroLibX "\033[0m"
	@make -C MacroLibX > /dev/null
	@make -C lib
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) lib/libft.a $(LIBS)
	echo "Compiling\033[1m\033[32m" $@ "\033[0m"
	echo "\033[42mSuccessfully compiled :)\033[0m"


bonus: $(OBJS_BONUS)
	@echo "\033[1m\033[32m""[ Bonus ]" "\033[0m"
	@echo "Compiling\033[1m\033[32m" MacroLibX "\033[0m"
	@make -C MacroLibX > /dev/null
	@make -C lib
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) lib/libft.a $(LIBS)
	echo "Compiling\033[1m\033[32m" $@ "\033[0m"
	echo "\033[42mSuccessfully compiled :)\033[0m"

norm:
	@clear
	@echo "\033[1m\033[32m""[ Norminette ]" "\033[0m"
	-@norminette $(SRCS) lib/ includes/ $(SRCS_BONUS)

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
	@rm -rf $(NAME) $(NAME_BONUS)

fclean_macro: clean
	@make fclean -C lib
	@make fclean -C MacroLibX
	@rm -rf $(NAME)
	@rm -rf MacroLibX

re:
	$(MAKE) fclean
	$(MAKE) -j$(nproc)

.PHONY: all clean fclean bonus re norm valgrind macro
