# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 10:49:06 by bapasqui          #+#    #+#              #
#    Updated: 2024/04/19 00:22:54 by baptiste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef VERBOSE
MAKEFLAGS += --no-print-directory --silent
endif

MAKEFLAGS += -j

# Makefile vars
CC := clang                                                             
NAME    := cube3d
CFLAGS  := -Wextra -Wall -Werror -g #-fsanitize=address -fsanitize=undefined
SRCS    := src/main.c \
		   src/interaction/event.c \
		   src/init/init_mlx.c \
		   src/render/render_player.c \
		   src/render/render_map.c \
		   src/interaction/movement.c \
		   src/utils/free_tab.c \


OBJS_DIR := obj
OBJS    := $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))
LIBS    := MacroLibX/libmlx.so -lSDL2 -lm

all: $(NAME)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@make -C MacroLibX
	@make -C lib/libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) lib/libft/libft.a $(LIBS)
	echo "Compiling\033[1m\033[32m" $@ "\033[0m"
	echo "\033[42mSuccessfully compiled :)\033[0m"

gt:	
	@if [ ! -d "MacroLibX" ]; then git clone https://github.com/seekrs/MacroLibX.git; fi

clean:
	@make -C lib/libft clean
	@make -C MacroLibX clean
	@rm -rf $(OBJS_DIR)

fclean: clean
	@make fclean -C lib/libft 
	@make fclean -C MacroLibX
	@rm -rf $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) -j$(nproc)

.PHONY: all clean fclean re gt