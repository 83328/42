# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 11:40:17 by alimpens          #+#    #+#              #
#    Updated: 2023/09/27 11:43:19 by alimpens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
NAME_BONUS = philo_bonus

CC = cc
CCFLAGS = -Wall -Wextra -Werror
CFLAGS = 
# CFLAGS = -fsanitize=thread	# it works it there is some error
# CFLAGS = -fsanitize=address	# it works if there is some error

RM = rm -rf

DEPS = header.h

SRCS_PHILOSOPHERS = main.c \
	checkers.c \
#	01_info.c \
	02_fork.c 
	philo.c \
	04_thread.c 
#	do_die.c \
	do_eat.c \
	do_sleep.c \
	do_think.c \
	routine.c \
	print.c \
	time.c 
	functions.c
SRCS_PHILOSOPHERS_BONUS = main_bonus.c

OBJS_PHILOSOPHERS = $(SRCS_PHILOSOPHERS:.c=.o)
OBJS_PHILOSOPHERS_BONUS = $(SRCS_PHILOSOPHERS_BONUS:.c=.o)

%.o: %.c $(DEPS)
	$(CC) $(CCFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS_PHILOSOPHERS)
	$(CC) $(CFLAGS) -o $@ $^

$(NAME_BONUS): $(OBJS_PHILOSOPHERS_BONUS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS_PHILOSOPHERS)
	$(RM) $(OBJS_PHILOSOPHERS_BONUS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re: fclean all

bonus: $(NAME_BONUS)

.PHONY: all clean fclean re bonus