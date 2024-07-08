# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bapasqui <bapasqui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 10:49:06 by bapasqui          #+#    #+#              #
#    Updated: 2024/07/08 22:41:17 by bapasqui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef VERBOSE
MAKEFLAGS += --no-print-directory --silent
endif

MAKEFLAGS += -j

# Makefile vars
CC := clang                                                             
NAME    := cub3D
CFLAGS  := -Wextra -Wall -Werror -g #-fsanitize=address
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
		   src/extras.c \
		   src/error.c \


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

gt:    
	@if [ ! -d "MacroLibX" ]; then git clone https://github.com/seekrs/MacroLibX.git; else rm -rf MacroLibX && git clone https://github.com/seekrs/MacroLibX.git; fi

norm:
	@norminette $(SRCS)

clean:
	@make -C lib clean
	@make -C MacroLibX clean
	@rm -rf $(OBJS_DIR)

fclean: clean
	@make fclean -C lib
	@make fclean -C MacroLibX
	@rm -rf $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) -j$(nproc)

.PHONY: all clean fclean re gt
