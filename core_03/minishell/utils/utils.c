#include "../minishell.h"

void	perror_exit(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	error_exit(char *msg)
{
	dprintf(2,"%s",msg);
	exit(EXIT_FAILURE);
}
