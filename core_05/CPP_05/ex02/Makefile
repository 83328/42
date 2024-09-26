NAME = Ex02
CC = c++
SRCS = $(shell find . -name "*.cpp")

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf *_shrubbery

re: fclean all

.PHONY: all clean fclean re