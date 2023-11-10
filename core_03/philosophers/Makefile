# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 11:40:17 by alimpens          #+#    #+#              #
#    Updated: 2023/11/10 14:57:39 by alimpens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CCFLAGS = -Wall -Wextra -Werror

RM = rm -rf

DEPS = header.h
SRC_DIR = philo

SRCS_PHILOSOPHERS = main.c \
	checkers.c \
	philo.c \
	functions.c
#	01_info.c \
	02_fork.c \
 	04_thread.c \
	do_die.c \
	do_eat.c \
	do_sleep.c \
	do_think.c \
	routine.c \
	print.c \
	time.c 

OBJS_PHILOSOPHERS = $(addprefix $(SRC_DIR)/, $(SRCS_PHILOSOPHERS:.c=.o))

%.o: $(SRC_DIR)/%.c $(DEPS)
	$(CC) $(CCFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS_PHILOSOPHERS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS_PHILOSOPHERS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re