NAME	=	minishell
SRC		=	minishell.c \
			subprocesses.c \
			utils/utils.c \
			utils/utils2.c \
			utils/copy_til_squote.c \
			utils/copy_til_dquote.c \
			utils/command_processing.c \
			utils/quotecheck.c \
			utils/quote_handling.c \
			utils/test_utils.c \
			utils/ft_str_revndup.c \
			utils/main_utils.c \
			utils/exiting.c \
			utils/expand_questionmarks.c \
			utils/exit_args.c \
			env/copy_env.c \
			env/copy_2d.c \
			env/set.c \
			signals/signals.c \
			strings/remove_from_2d.c \
			strings/ft_concat.c \
			strings/split_by_index.c \
			strings/concat_strings.c \
			splitting/pipe_split.c \
			splitting/space_split.c \
			splitting/space_finder.c \
			expansion/line_expansion.c \
			expansion/line_expansion_utils.c \
			expansion/expand_var.c \
			expansion/string_processing.c \
			redirection/rem_redir.c \
			redirection/open_files.c \
			redirection/open_files_nospace.c \
			redirection/ft_heredoc.c \
			redirection/token_splitting.c \
			execution/mod_execve_a.c \
			execution/mod_execve_b.c \
			env/ft_getenv.c \
			builtins/builtin_check.c \
			builtins/cd.c \
			builtins/echo.c \
			builtins/pwd.c \
			builtins/unset.c \
			builtins/env.c \
			builtins/export.c \
			builtins/export_set.c \
			builtins/export_check.c \
			freeing/freeing_a.c \
			freeing/freeing_b.c \
			execution/dup_io.c

OBJ = $(SRC:.c=.o)
LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a
READLINE_LIB = -lreadline
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)
CC				=	cc
RM 				=	rm -rf
CFLAGS			= 	-g -Wall -Wextra -Werror
all: $(LIBFT) $(NAME)
$(LIBFT):
	@make -C $(LIBFT_PATH)
	
$(NAME) : $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT) $(READLINE_LIB)
clean:
	@$(RM) $(OBJ)
	@make -C $(LIBFT_PATH) clean
fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_PATH) fclean
re : fclean all
.PHONY: all fclean re bonus