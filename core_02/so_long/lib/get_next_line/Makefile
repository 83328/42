# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/25 22:22:19 by alimpens          #+#    #+#              #
#    Updated: 2023/08/25 22:22:21 by alimpens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	get_next_line.a
INCLUDE		=	-I../../include
SRCS_DIR	=	src/
OBJS_DIR	=	obj/
FT_PRINTF	=	../ft_printf/libftprintf.a

AR			=	ar rcs
RM			=	rm -f
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

SRC_FILES	=	get_next_line get_next_line_utils	

SRCS		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS		=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C ../ft_printf
			cp $(FT_PRINTF) $(NAME)
			@$(AR) $(NAME) $(OBJS)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
			@mkdir -p $(@D)
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
			
clean:
			$(RM) -rf $(OBJS_DIR)
			@make clean -C ../ft_printf

fclean:		clean
			$(RM) -f $(NAME)
			@$(RM) -f $(FT_PRINTF)

re:			fclean all

.PHONY:		all clean fclean re
