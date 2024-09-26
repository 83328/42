# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/14 18:28:03 by alimpens          #+#    #+#              #
#    Updated: 2024/07/17 16:24:47 by alimpens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PhoneBook
SRCS = $(shell find -iname "*.cpp")

CC = c++
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -std=c++98 -pedantic

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	c++ $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re
