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

# .DEFAULT_GOAL := all

NAME := libftprintf.a

RM := rm -frv
CC := cc
CFLAGS := -Wall -Wextra -Werror
MAKEFLAGS := --no-print-directory

LIBFT_SRC := ../libft

LDFLAGS := -I. -I$(LIBFT_SRC)
LDLIBS :=

LIBFT_OBJ := \
	ft_putchar_fd.o \
	ft_strdup.o \
	ft_strlen.o \
	ft_putstr_fd.o \
	ft_putnbr_fd.o \
	ft_strlcpy.o \
	ft_strjoin.o \
	ft_calloc.o \
	ft_memcpy.o \
	ft_bzero.o \
	ft_memset.o \
	ft_itoa.o

SOURCES := \
	ft_printf.c \
	ft_printf_string.c \
	ft_printf_integer.c \
	ft_printf_hex.c

OBJECTS := $(patsubst %.c,%.o,$(SOURCES))

all: LIBFT $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@ $(LDLIBS)

LIBFT:
	@make -C $(LIBFT_SRC) all

$(NAME): $(OBJECTS)
	$(AR) -x $(LIBFT_SRC)/libft.a $(LIBFT_OBJ)
	$(AR) -rcs $@ $^ $(LIBFT_OBJ)
	ranlib $@

clean :
	@make -C $(LIBFT_SRC) clean
	@$(RM) $(OBJECTS) $(LIBFT_OBJ)

fclean : clean
	@make -C $(LIBFT_SRC) fclean
	@$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
