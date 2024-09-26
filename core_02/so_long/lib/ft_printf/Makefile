# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 16:47:22 by alimpens          #+#    #+#              #
#    Updated: 2023/01/02 20:09:52 by alimpens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC			= cc
CFLAGS		= -Wall -Werror -Wextra -I./include/

AR			= ar rcs

RM			= rm -f

INCLUDES = ./ft_printf.h

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SRCS =	ft_printf.c \
	ft_search_arg.c \
	ft_count_digits.c \
	ft_print_char.c \
	ft_putstr.c \
	ft_print_perc.c \
	ft_print_ptr.c \
	ft_print_int.c \
	ft_print_unsigned.c \
	ft_print_hex.c \
	ft_print_upper_hex.c \
	ft_count_unsigned_digits.c \
	
OBJS = $(SRCS:.c=.o)

all:		$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

clean:
			$(RM) $(OBJS)
			@echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"

fclean:		clean
			$(RM) $(NAME)
			@echo "$(CYAN)ft_printf executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

norm:
			@norminette $(SRCS) $(INCLUDES) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm