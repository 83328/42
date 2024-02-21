#include "minishell.h"

int	pipex_plus(int ac, char **av, char **env, t_struct *stru)
{

	int	i;

	if (stru->filefds[0][0])
		dup2(stru->filefds[0][0],STDIN);
	i = 1;
	while (i < ac )
	{
		redir_exec(av[i], env, i, stru);
		i++;
	}
	if (stru->filefds[i-1][1])
		dup2(stru->filefds[i-1][1],STDOUT);
	mod_execve(av[i], env);
	//redir_exec(av[i], env, i, stru, 1);
	return(1);
}