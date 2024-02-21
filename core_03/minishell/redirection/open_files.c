#include "../minishell.h"

void    open_files(t_struct *stru, int index) //potentially add the option of no space  
{
    int i;

    i = 0;
    while (stru->split_by_space[i])
	{
		if (stru->split_by_space[i][0] == '<')
		{
			printf("\n< found");
			if (stru->split_by_space[i + 1])
			{
				if (stru->filefds[index][0] != 0)
					stru->unused_fds[stru->ufd_i++] = stru->filefds[index][0];
				stru->filefds[index][0] = open(stru->split_by_space[i + 1], O_RDONLY);
				if (stru->filefds[index][0] == -1)
				{
					printf("\nError opening file");
					return;
				}
			}
			else
				printf("\nno file after <");
		}
		if (stru->split_by_space[i][0] == '>')
		{
			printf("\n> found");
			if (stru->split_by_space[i + 1])
			{
				if (stru->filefds[index][1] != 0)
				{
					printf("\nfd to unused");
					stru->unused_fds[stru->ufd_i++] = stru->filefds[index][1];
				}
				stru->filefds[index][1] = open(stru->split_by_space[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
				if (stru->filefds[index][1]  == -1)
				{
					printf("\nError opening file");
					return;
				}
			}
			else
				printf("\nno file after > ");
		}
		i++;
	}
}

void    terminate_filefds(t_struct *stru, int index)
{
	stru->unused_fds[stru->ufd_i] = -1;
    stru->filefds[index][0] = -1;
    stru->filefds[index][1] = -1;
}