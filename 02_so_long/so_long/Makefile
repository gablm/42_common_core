# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfragoso <gfragoso@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 18:37:48 by gfragoso          #+#    #+#              #
#    Updated: 2024/03/18 18:38:27 by gfragoso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long

COMPILER=cc
FLAGS=-Wall -Wextra -Werror

FILES= get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		so_long.c dispose.c map_load.c map_print.c kbhandler.c map_verify.c \
		map_verify_path.c
HEADERS=so_long.h
LIBS= -Llibft/ -lft -Lprintf/ -lftprintf -lm -Lminilibx-linux/ -lmlx_Linux -lX11 -lXext

all: $(NAME)

$(NAME): $(FILES) $(HEADERS)
	$(MAKE) -C libft all
	$(MAKE) -C printf all
	$(MAKE) -C minilibx-linux
	$(COMPILER) $(FLAGS) $(FILES) -o $(NAME) $(LIBS)

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C printf clean
	$(MAKE) -C minilibx-linux clean

fclean:
	$(MAKE) -C libft fclean
	$(MAKE) -C printf fclean
	$(MAKE) -C minilibx-linux clean
	rm -fr $(NAME)

re: fclean all
