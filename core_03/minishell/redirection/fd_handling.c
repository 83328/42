#include "../minishell.h"

void    *fake_open_fds(char **split_by_spaces, t_struct *stru) //opens all files in strings that contain redirection operators and stores them in fd_ins/fd_outs
{
	int		i;

	i = 0;
	stru->filefdin = 0;
	stru->filefdout = 0;
	while (split_by_spaces[i])
	{
		if (split_by_spaces[i][0] == '<')
		{
			printf("\n< success");
			if (split_by_spaces[i + 1])
			{
				stru->filefdin = open(split_by_spaces[i + 1], O_RDONLY);
				if (stru->filefdin == -1)
				{
					printf("\nError opening file");
					return 0;
				}
			}
			else
				printf("\nerror after <");
		}
		if (split_by_spaces[i][0] == '>')
		{
			printf("\n> success");
			if (split_by_spaces[i + 1])
			{
				stru->filefdout = open(split_by_spaces[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
				if (stru->filefdout == -1)
				{
					printf("\nError opening file");
					return 0;
				}
			}
			else
				printf("\nerror after >");
		}
		i++;
	}
	return 0;
}

void	fd_handling(int i, t_struct *stru)
{
	if (i == 0)
		stru->fdin = STDIN;
	else
		stru->fdin = stru->inpipe;
	if (stru->filefdin)
	{
		stru->fdin = stru->filefdin;
		stru->filefdin = 0;
	}
	else	
		stru->fdin = stru->inpipe;
	if (stru->input_by_pipes[i + 1] == 0)
		stru->fdout = STDOUT;
	else	
		stru->fdout = stru->outpipe;
}