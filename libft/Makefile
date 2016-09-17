#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 15:40:28 by gtandeo           #+#    #+#              #
#    Updated: 2014/12/08 12:36:03 by gtandeo          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC = ft_atoi.c \
		ft_bzero.c \
		ft_itoa.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_print_tab.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strndup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_tablen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_fill_str.c \
		ft_fill_tab.c \
		get_next_line.c

CFLAGS = -Wall -Werror -Wextra

NAME = libft.a

OBJ = $(SRC:.c=.o)

HEAD = libft.h

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo ""
	@echo "\033[33m"libft.a Compiled ! "\033[32m"Success

$(OBJ): $(HEAD)

%.o: %.c
	@echo -n .
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	@echo "\033[33m"Objects Deleted ! "\033[32m"Success
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: fclean re
