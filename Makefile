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

LIB_DIR	:=	libraries/
SRC_DIR	:=	src/

LIBFT_SRC := ./$(LIB_DIR)libft
GETNEXTLINE_SRC := ./$(LIB_DIR)getnextline
FTPRINTF_SRC := ./$(LIB_DIR)ftprintf
MINILIBX_SRC := ./$(LIB_DIR)minilibx

LDFLAGS := \
	-I ./ \
	-I $(LIBFT_SRC) \
	-I $(FTPRINTF_SRC) \
	-I $(MINILIBX_SRC) \
	-I $(GETNEXTLINE_SRC)

LDLIBS := \
	-lXext -lX11 -lm -lz \
	-L $(LIBFT_SRC) -lft \
	-L $(FTPRINTF_SRC) -lftprintf \
	-L $(MINILIBX_SRC) -lmlx_Linux

SOURCES := ./$(SRC_DIR)main.c \
	./$(SRC_DIR)error.c \
	./$(SRC_DIR)extract_map.c

OBJECTS := $(patsubst %.c,%.o,$(SOURCES))

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

all: LIBS $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@

LIBS:
	@make $(MAKEFLAGS) -C $(MINILIBX_SRC) all
	@make $(MAKEFLAGS) -C $(FTPRINTF_SRC) all
	@make $(MAKEFLAGS) -C $(LIBFT_SRC) all

clean:
	@make $(MAKEFLAGS) -C $(MINILIBX_SRC) clean
	@make $(MAKEFLAGS) -C $(FTPRINTF_SRC) clean
	@make $(MAKEFLAGS) -C $(LIBFT_SRC) clean
	@$(RM) $(OBJECTS)

fclean: clean
	@make $(MAKEFLAGS) -C $(FTPRINTF_SRC) fclean
	@make $(MAKEFLAGS) -C $(LIBFT_SRC) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
