# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/31 22:56:16 by grcharle          #+#    #+#              #
#    Updated: 2025/06/30 06:23:13 by grcharle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL := all

NAME := libftprintf.a

RM := rm -frv
CC := cc
CFLAGS := -Wall -Wextra -Werror

AR := ar

MAKEFLAGS := --no-print-directory

LIBFT_SRC := ../libft/

LIBFT_SOURCES := $(shell find $(LIBFT_SRC) -type f -name 'ft_*.c')

SOURCES := \
	ft_printf.c \
	ft_printf_string.c \
	ft_printf_integer.c \
	ft_printf_hex.c

OBJECTS := $(patsubst %.c,%.o,$(SOURCES) $(LIBFT_SOURCES))

all : LIBS $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

LIBS:
	@make $(MAKEFLAGS) -C $(LIBFT_SRC) all

$(NAME): $(OBJECTS) $(LIBFT_OBJ)
	$(AR) -rcs $@ $^ $(LIBFT_OBJ)
	ranlib $@

clean :
	@make $(MAKEFLAGS) -C $(LIBFT_SRC) clean
	@$(RM) $(OBJECTS)

fclean : clean
	@make $(MAKEFLAGS) -C $(LIBFT_SRC) fclean
	@$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
