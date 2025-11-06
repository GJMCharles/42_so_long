# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/31 09:32:25 by grcharle          #+#    #+#              #
#    Updated: 2025/11/06 19:46:22 by grcharle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL := all

NAME := so_long

RM := rm -frv
CC := cc
CFLAGS := -Wall -Wextra -Werror
MAKEFLAGS := --no-print-directory

LIB_DIR := ./libraries
SRCS_DIR := ./srcs/

LIBFT_SRC := $(LIB_DIR)/libft
FTPRINTF_SRC := $(LIB_DIR)/ftprintf
MINILIBX_SRC := $(LIB_DIR)/minilibx

LDFLAGS := \
	-I ./ \
	-I $(LIBFT_SRC) \
	-I $(FTPRINTF_SRC) \
	-I $(MINILIBX_SRC)

LDLIBS := \
	-L $(LIBFT_SRC) -lft \
	-L $(FTPRINTF_SRC) -lftprintf \
	-L $(MINILIBX_SRC) -lmlx_Linux \
	-lXext -lX11 -lm -lz

SRCS_FILE := \
	main.c \
	init_game/create_game.c \
	init_game/is_playable.c \
	init_game/map_error.c \
	init_game/parsing.c \
	init_game/map_creation.c \
	init_game/texture_status.c \
	init_game/verif_ext.c \
	init_game/free_func.c \
	in_game/struct_func.c \
	in_game/movements.c \
	in_game/game_status.c \
	render/render_map.c

SOURCES := $(addprefix $(SRCS_DIR), $(SRCS_FILE))
OBJECTS := $(patsubst %.c,%.o,$(SOURCES))

all: LIBS $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@

LIBS:
	@make $(MAKEFLAGS) -C $(FTPRINTF_SRC) all
	@make $(MAKEFLAGS) -C $(MINILIBX_SRC) all

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

norm:
	norminette -R CheckForniddenHeader libraries/libft libraries/ftprintf srcs

runtest: all
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/empty_map_2.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/empty_map.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/false_map.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/map_too_big_1.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/map_too_big.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/map.txt
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/no_collectible.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/no_player.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/no_exit.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/not_rect_map.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/open_map_2.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/open_map.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/two_exit.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/two_player.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/unreachable_ex.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/unreachable_col.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/small_map.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) maps/map.ber

clean:
	@make $(MAKEFLAGS) -C $(FTPRINTF_SRC) clean
	@make $(MAKEFLAGS) -C $(MINILIBX_SRC) clean
	@$(RM) $(OBJECTS)

fclean: clean	
	@make $(MAKEFLAGS) -C $(FTPRINTF_SRC) fclean
	@$(RM) $(NAME)


re: fclean all

.PHONY: all clean fclean re norm runtest
