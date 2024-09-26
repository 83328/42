NAME = harlFilter
CC = c++
SRCS = $(shell find -iname "*.cpp")

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address -pedantic
OBJS = $(SRCS:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re
