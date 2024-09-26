# define
NAME		=	so_long
INCLUDE		=	-I./include -I $(LIBMLX)/include/MLX42

# directory
SRCS_DIR	=	src/
OBJS_DIR	=	obj/
GETNL_DIR	=	./lib/get_next_line
LIBFT_DIR	=	./lib/libft
LIBMLX		=	./lib/MLX42

# path (.a file)
GETNL_PATH		=	lib/get_next_line/get_next_line.a
LIBFT_PATH		=	lib/libft/libft.a
PRINTF_PATH		=	lib/ft_printf/libftprintf.a

# all path (all .a file)
LIB_PATH		= $(GETNL_PATH) $(LIBFT_PATH) $(PRINTF_PATH)

# executables
AR			=	ar rcs
RM			=	rm -f
CC			=	cc -g3
CFLAGS		=	-Wall -Wextra -Werror

# leak
VALGRIND	=	@valgrind --leak-check=full

# mlx library 
MLX_PATH	=	./lib/MLX42/build/libmlx42.a
MFLAGS		=	-L./lib/MLX42/build -lmlx42 -Iinclude -ldl -lglfw -pthread -lm

###

GREEN	= \033[0;32m]
BLUE	= \033[0;34m]
RESET	= \033[0m]
BOLD	= \033[1m]
WHITE	= \033[37m]

# sources

SRC_FILES	=	so_long \
				ft_error utility valid_map init_game init_map init_image enemies init_floor \
				place_image_to_window event delete_image display_move flood_fill


SRCS		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS		=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C $(GETNL_DIR)
			@make -C $(LIBFT_DIR) 
			@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
			@echo "- $(BOLD)Compiling$(RESET) $(NAME)\n"	
			$(CC) -g $(CFLAGS) $(MFLAGS) $(OBJS) \
			$(LIB_PATH) $(MLX_PATH) -o $(NAME)
			@echo "	$(GREEN)$(BOLD)[so_long]$(RESET) $(WHITE)compiled!$(RESET)"	

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c ./include/so_long.h
			@mkdir -p $(@D)
			@echo -n "["
			@echo -n $$(expr $$(echo "$$(ls -1 $(OBJS_DIR) | wc -l) * 100 / $$(echo "$(SRC_FILES)" | wc -w)" | bc) / 1)
			@echo "%] $(GREEN)Building so long $@$(RESET)"
			$(CC) -g $(INCLUDE) -c $< -o $@

clean:
			$(RM) -rf $(OBJS_DIR)
			$(RM) -rf $(LIBMLX)/build
			@make clean -C $(GETNL_DIR)
			@make clean -C $(LIBFT_DIR)
			@echo "	$(BLUE)$(BOLD)[so_long]$(RESET) objects files $(BLUE)cleaned$(RESET)!"

fclean:		clean
			$(RM) -f $(NAME)
 			# @$(RM) -f $(LIB_PATH) 
			@echo "	$(BLUE)$(BOLD)[ALL PATH]$(RESET) executable files $(BLUE)cleaned$(RESET)!"

re:			fclean all
			@echo "	$(GREEN)$(BOLD)[so_long]$(RESET) $(BOLD)cleaned and rebuilt everything$(RESET)!"

LIBFT		= ./lib/libft/
# LIBMLX 		= ./lib/MLX/
LIBMLX42	= ./lib/MLX42/

# GIT_MLX		= git clone https://github.com/42Paris/minilibx-linux $(LIBMLX)
GIT_MLX42	= git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX42)
CREAR		= clear

download_mlx:
	$(GIT_MLX)
	make -C $(LIBMLX) --no-print-directory

download_mlx42:
	$(GIT_MLX42)
	cd $(LIBMLX42) && cmake -B build
	cd $(LIBMLX42) && cmake --build build -j4

undownload_mlx42:
	rm -rf $(LIBMLX42)
	
.PHONY:		all clean fclean re
