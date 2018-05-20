# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lprior <lprior@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/19 20:34:32 by lprior            #+#    #+#              #
#    Updated: 2018/05/19 21:04:12 by lprior           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror

SRC_DIR = srcs/

NAME = my_vm

FILES = $(SRC_DIR)main.c \
		$(SRC_DIR)open.c \
		$(SRC_DIR)operations.c \
		$(SRC_DIR)stack.c \
		$(SRC_DIR)error.c

HEADERS = ./includes

SRCS = $(addprefix $(SRC_DIR)/,$(FILES))

OBJS =   $(FILES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS) $(HEADERS)
	@gcc $(CFLAGS) -I $(HEADERS) $(OBJS) -lncurses -o $(NAME)

%.o: %.c
	@gcc $(CFLAGS) -I $(HEADERS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
