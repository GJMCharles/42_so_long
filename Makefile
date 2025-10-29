# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grcharle <grcharle@42student.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/29 22:11:15 by grcharle          #+#    #+#              #
#    Updated: 2025/09/29 22:18:26 by gjmcharles       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL := all

NAME := so_long

RM := rm -frv
CC := cc
CFLAGS := -Wall -Wextra -Werror
MAKEFLAGS := --no-print-directory

LIBFT_SRC := ./libft
FTPRINTF_SRC := ./ftprintf
MINILIBX_SRC := ./minilibx

LDFLAGS := \
	-I ./ \
	-I $(MINILIBX_SRC) \
	-I $(FTPRINTF_SRC) \
	-I $(LIBFT_SRC)

LDLIBS := \
	-lXext -lX11 \
	-L$(FTPRINTF_SRC) -lftprintf \
	-L$(LIBFT_SRC) -lft

SOURCES := so_long.c

OBJECTS := $(patsubst %.c,%.o,$(SOURCES))

$(NAME): $(OBJECTS)

all: LIBS $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@

LIBS:
	@make -C $(MINILIBX_SRC) all
	@make -C $(FTPRINTF_SRC) all
	@make -C $(LIBFT_SRC) all

clean:
	@make -C $(MINILIBX_SRC) clean
	@make -C $(FTPRINTF_SRC) clean
	@make -C $(LIBFT_SRC) clean
	@$(RM) $(OBJECTS)

fclean: clean
	@make -C $(FTPRINTF_SRC) fclean
	@make -C $(LIBFT_SRC) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
