# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/31 09:32:25 by grcharle          #+#    #+#              #
#    Updated: 2025/10/31 09:38:32 by grcharle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS 	:=	--no-print-directory

NAME		=	so_long
CC		=	cc
CFLAGS		=	-Wall -Wextra -Werror

INCLUDE		=	incs/
INCLUDE_BONUS	=	incs_bonus/
SRCS_BONUS_DIR	=	srcs_bonus/
SRCS_DIR	=	srcs/
LIBFT		=	libft/
MLX_DIR		=	mlx/
OBJ_DIR		=	obj/

RM		=	rm -frv

SRC_FILE =	init_game/create_game.c \
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
		render/render_map.c \
		main.c

SRCS = $(addprefix $(SRCS_DIR), $(SRC_FILE))
OBJ  = $(addprefix $(OBJ_DIR), $(SRC_FILE:.c=.o))

OBJF = .cache_exists

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(MLX_DIR)
	@make -C $(LIBFT)
	@$(CC) -o $(NAME) $(CFLAGS) -I$(INCLUDE) $(OBJ) -L$(LIBFT) -lcustomft -L$(MLX_DIR) -lmlx -lX11 -lXext

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c | $(OBJF)
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(OBJF):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/init_game
	@mkdir -p $(OBJ_DIR)/in_game
	@mkdir -p $(OBJ_DIR)/render

runtest: all
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/empty_map_2.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/empty_map.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/false_map.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/map_too_big_1.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/map_too_big.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/map.txt
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/no_collectible.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/no_player.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/no_exit.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/not_rect_map.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/open_map_2.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/open_map.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/two_exit.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/two_player.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/unreachable_ex.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/unreachable_col.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/small_map.ber
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) map/map.ber

norminette:
	norminette -R CheckForniddenHeader incs libft srcs

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -sC $(LIBFT)
	@make clean -sC $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re runtest norminette


