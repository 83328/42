#ifndef MINISHELL_H
# define MINISHELL_H
# define MAX_ARGS 150

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <linux/limits.h>
#include "libft/libft.h"
#include <signal.h>

extern int global_sig;

typedef struct s_prompt
{
	int		word_number;
	char	**prompt;
}			t_prompt;

void	perror_exit(const char *message);
char    *line_expansion(char *input_line);
//int		mod_execvp(const char *file, char *const argv[], char *PATH);
char	*dollars_expansion(char *string);

char* expand_var(char* string, char* value, int start, int var_len); 
char* get_p_var(char* string, int start);

//pathfuncs.c
char    *alloc_full_path(const char *folder, const char *file);
char    *find_command_path(const char *file, char *PATH);
int		mod_execvp(const char *file, char *const argv[], char *PATH);
char    *path_from_env(char *path_word, char **env);

void sigint_handler(int sig);

//test_utils
void printStringArray(char **strArray);

//echo.c
int echo_command(int ac, char *av[]);
//int is_exit_command(const char* input);

//pwd.c
char* pwd(void);

//env.c
void env_command();


//cd.c
int cd_command(int argc, char *argv[]);

//unset.c
int unset_command(char *variable);

//export.c
void export_command(char *variable);

#endif