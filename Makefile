# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/07 10:52:01 by gtandeo           #+#    #+#              #
#    Updated: 2016/09/01 15:40:32 by gtandeo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft/libft.a

LIBDIR = libft

NM = ft_nm

OTOOL = ft_otool

SRCS = srcs/

SRC_NM = main_nm.c \
		list.c \
		swap.c \
		print.c \
		handle_32.c \
		handle_64.c \
		handle_fat.c \
		segment.c \
		error.c

SRC_OTOOL = main_otool.c \
			print_otool.c \
			swap.c \
			print.c \
			otool_struct.c \
			error.c

SRCO = $(SRC:.c=.o)

INCDIR = ./includes

CFLAGS = -Wall -Wextra -Werror

all: $(LIB) $(NM) $(OTOOL)

$(LIB):
	@make -C $(LIBDIR) fclean
	@make -C $(LIBDIR)

$(NM): $(LIB) $(addprefix $(SRCS),$(SRC_NM))
	@cc -o $(NM) $(addprefix $(SRCS),$(SRC_NM)) $(CFLAGS) -L libft -lft -I $(INCDIR)
	@echo "\033[33m"ft_nm Compiled ! "\033[32m"Success

$(OTOOL): $(LIB) $(addprefix $(SRCS),$(SRC_OTOOL))
	@cc -o $(OTOOL) $(addprefix $(SRCS),$(SRC_OTOOL)) $(CFLAGS) -L libft -lft -I $(INCDIR)
	@echo "\033[33m"ft_otool Compiled ! "\033[32m"Success

clean:
	@rm -f $(SRCO)
	@make fclean -C $(LIBDIR)

fclean: clean
	@rm -f $(NM)
	@echo "\033[33m"ft_nm Deleted ! "\033[32m"Success
	@rm -f $(OTOOL)
	@echo "\033[33m"ft_otool Deleted ! "\033[32m"Success

re: fclean all

.PHONY: fclean re
