#ifndef MINISHELL_H
# define MINISHELL_H
# define MAX_ARGS 100

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

char    *line_expansion(char *input_line);
//int		mod_execvp(const char *file, char *const argv[], char *PATH);
char	*dollars_expansion(char *string);


char* expand_var(char* string, char* value, int start, int var_len); 
char* get_p_var(char* string, int start);


//test_utils
void printStringArray(char **strArray);

//echo.c
int echo_command(int ac, char *av[]);
int is_quote(char c);
void process_quotes(char *token);

int is_exit_command(const char* input);

//pwd.c
char* pwd(void);

//env.c

//cd.c

//unset.c

//export.c


#endif