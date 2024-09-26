# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 20:26:36 by alimpens           #+#    #+#              #
#    Updated: 2023/06/21 12:10:50 by alimpens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror #-g3 -fsanitize=address
NAME	= push_swap

SRCS	= checkers.c \
			operations_swap.c \
			operations_push.c \
			operations_rotate.c \
			operations_rrotate.c \
			push_swap.c \
			stack_ops.c \
			sort_2.c \
			sort_3.c \
			sort_4.c \
			sort_5.c \
			utils.c \
			turk_method.c \
			push_from_a_to_b.c \
			is_ordered.c \
			fill_moves_n_steps.c \
			position_in_b.c \
			distance_from_top.c \
			position_in_a.c \

OBJS	= $(SRCS:.c=.o)

DEPS	=	./push_swap.h \
			./turk_method.h

%.o: %.c
		$(CC) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
