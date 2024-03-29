/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:41:46 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/26 16:56:49 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//#include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <string.h>
# include <unistd.h>
# include <linux/limits.h>
# include "libft/libft.h"
# include <signal.h>
# include <sys/ioctl.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define INFILE 0
# define OUTFILE 1

extern int	global_sig;

typedef struct s_struct
{
	char	**env_copy; //DONT FREE
	int		env_copy_size; //DONT FREE
	char	*input; //free
	char	**split_by_space; //free
	char	**reassembled_commands; //free
	char	**input_by_pipes; //free
	int		(*filefds)[2]; //free
	int		**pipefds; //free
	pid_t	*pids; //unsure
	char	*line; //leave out
	int		unused_fds[8192]; //free
	int		ufd_i;
	int		exit_status; //leave out
	int		*exit_statuses; //leave out
	int		flag; //leave out
}			t_struct;

void	execute_command(char **split_by_space);
void	sigint_handler_default(int sig); 
void	sigint_handler_heredoc(int sig);
void	sigint_handler_command(int sig);
void	copy_env(char *envp[], t_struct *str);
int		mod_execvp(const char *file, char *const argv[], char *PATH);
void	perror_exit(char *msg);
void	error_exit(char *msg);
char	**copy_2d(char **envp, char **envp_copy);
int		piping(int ac, char **av, char **env);
void	open_files(t_struct *stru, int index);
void	terminate_filefds(t_struct *stru, int index);
void	rem_redir(char **split_by_spaces);
char	**pipe_split(char *input);
char	**split_by_index(char *input, int *indices);
char	**space_split(char *string);
char	*line_expansion(char *line, t_struct *stru);
char	*copy_til_dquote(char *line, int i);
char	*copy_til_squote(char *line, int i);
char	*ft_concat(char *s1, char *s2);
char	*ft_getenv(const char *varname, char **env_copy);
int		ft_heredoc(int index, t_struct *stru, char *delimiter);
void	*signal_handling();
char	**remove_from_2d(char **array, int index);
int		ft_array_len(char **array);
int		quote_errors(char *input);

char	*concat_strings(char **strings, int numstrings);
void	redir_exec(char *command, char **env, int i, t_struct *stru);
//void	mod_execve(char *command, char **env);
void	mod_execve(char *command, char **env, t_struct *stru);
void	subprocesses(int len, char **reassembled_commands, char **envp, t_struct *stru);
void	set(char *name, char *value, t_struct *big);
int		unset(char **envp, const char *varname);

void	resize_env_copy(t_struct *stru);
char	**char2d_realloc(char **ptr, int size, int old_size);
char	*ft_str_revndup(const char *str, int n);

//builtins
int		is_builtin(char *cmd);

//echo
// int echo_command(int ac, char *av[]);
void	echo_command(char *str);

//pwd
void	pwd_command(void);

//cd
//char **cd_command(char **args, char **env);
void	update_env_var(char *var, char *new_value, char **envp);
void	cd_command(t_struct *stru, char *args[]);

//env
void	env_command(t_struct *stru);
//unset
//int unset_command(char *variable);
int		unset_command(char **env_cp, const char *varname);
//export
//void	export_command(char **args);
//void	export_command(char *name, char *value, t_struct *stru);
void	export_command(char *value, t_struct *stru);
int		is_valid_identifier(char *s);
void	add_to_env(t_struct *stru, char *new_var);
//void	add_to_envcopy(char *name, char *value, t_struct *stru);
//void	rebuild_environ(char **env_copy, int size);

//test_utils
void	print_string_array(char **strArray);
void	print_int_array(int *intArray);
void	print_file_content(int fd);

//utils.c
void	error_exit(char *msg);
void	free_loopend(t_struct *stru, int len);
/*void	free_child(t_struct *stru);
void	free_exit(t_struct *stru); */

//freeing.c
void	free(void *ptr);
void	free_2d(char **array);
void	freepidarr(t_struct *stru);
void	free_2dint(int **array, int len);
void	free_ufds(t_struct *stru);
void	free_filefds(t_struct *stru);
#endif