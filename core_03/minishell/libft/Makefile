# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 02:39:23 by dgacic            #+#    #+#              #
#    Updated: 2024/03/20 14:04:35 by alimpens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strcpy.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_striteri.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strndup.c \
			ft_strnstr.c \
			ft_strtok.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_lstadd_back.c \
			ft_printf.c \
			ft_printf_utils.c \
			ft_strcmp.c

OBJ		=	$(SRC:.c=.o)

NAME		=	libft.a
CC		=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM		= 	rm -f

.PHONY:		all clean fclean re 

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rcs $(NAME) $(OBJ)
		

clean:		
		$(RM) $(OBJ)

fclean:		
		$(RM) $(OBJ) $(NAME)

re:		fclean $(NAME)
