# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/16 15:52:12 by grcharle          #+#    #+#              #
#    Updated: 2025/10/16 16:13:50 by grcharle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

RM := rm -rfv
CC := cc
CFLAGS := -Wall -Wextra -Werror
MAKEFLAGS := --no-print-directory

LIBFT_SRC := ./libft
FTPRINTF_SRC := ./ftprintf
MINILIBX_SRC := ./minilibx

LDFLAGS := -I ./ \
	-I $(LIBFT_SRC) \
	-I $(FTPRINTF_SRC)

LDLIBS := -lXext -lX11

SOURCES := so_long.c

OBJECTS := $(patsubst %.c,%.o,$(SOURCES))

all: LIBS $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@

LIBS:
	@make -C $(LIBFT_SRC) all
	@make -C $(FTPRINTF_SRC) all
	@make -C $(MINILIBX_SRC) all

$(NAME): $(OBJECTS)

clean:
	@make -C $(LIBFT_SRC) clean
	@make -C $(FTPRINTF_SRC) clean
	@make -C $(MINILIBX_SRC) clean

fclean: clean
	@make -C $(LIBFT_SRC) fclean
	@make -C $(FTPRINTF_SRC) fclean

re: fclean all

.PHONY: all clean fclean re
