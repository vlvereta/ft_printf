# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/23 14:17:49 by vlvereta          #+#    #+#              #
#    Updated: 2018/01/23 14:26:24 by vlvereta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

OBJ =	ft_printf.o \
		extra.o \
		struct_init.o \
		types_high_dounp.o \
		types_low_c.o \
		types_low_dioux.o \
		./libft/ft_atoi.o \
		./libft/ft_bzero.o \
		./libft/ft_isdigit.o \
		./libft/ft_islower.o \
		./libft/ft_itoa_base.o \
		./libft/ft_putchar.o \
		./libft/ft_strdup.o \
		./libft/ft_strlen.o \
		./libft/ft_strnew.o \
		./libft/ft_toupper.o \
		./libft/ft_isascii.o \
		./libft/ft_memset.o \
		./libft/ft_strcpy.o

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	make -C libft/
	$(CC) -c $< -o $@

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean $(NAME)
