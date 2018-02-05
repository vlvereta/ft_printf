# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/23 14:17:49 by vlvereta          #+#    #+#              #
#    Updated: 2018/01/30 08:46:54 by vlvereta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

OBJ =	ft_printf.o \
		./extra/extra_functions.o \
		./extra/initialization.o \
		./extra/percent_and_co.o \
		./extra/type_high_c.o \
		./extra/type_di.o \
		./extra/type_pox.o \
		./extra/type_low_s.o \
		./extra/type_high_s.o \
		./extra/type_unsigned.o \
		./extra/additional_types_or_flags.o \
		./libft/ft_atoi.o \
		./libft/ft_bzero.o \
		./libft/ft_isdigit.o \
		./libft/ft_islower.o \
		./libft/ft_itoa_base.o \
		./libft/ft_putchar.o \
		./libft/ft_strdup.o \
		./libft/ft_strjoin.o \
		./libft/ft_strlen.o \
		./libft/ft_strncpy.o \
		./libft/ft_strnew.o \
		./libft/ft_strsub.o \
		./libft/ft_toupper.o \
		./libft/ft_isascii.o \
		./libft/ft_memset.o \
		./libft/ft_strcpy.o

LIBFT = make -C libft/

all: $(NAME)

$(NAME): $(OBJ)
	$(LIBFT)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean $(NAME)
