NAME = Accounts
SRCS = Account.cpp tests.cpp

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