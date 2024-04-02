/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:38:04 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/02 20:44:37 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_global_sig = 0;

int	quote_errors(char *input)
{
	int	i;

	i = 0;
	while(input[i])
	{
		while (input[i] != 0 && input[i] != 39 && input[i] != 34)
			i++;
		if (input[i] == 39 || input[i] == 34)
		{
			if(input[i] == 39)
			{
				i++;
				while (input[i] != 39)
				{
					if (input[i] == 0)
					{
						ft_putendl_fd("unclosed single quote, invalid input", STDERR_FILENO);
						return (1);
					}
					i++;
				}
			}
			if (input[i] == 34)
			{
				i++;
				while (input[i] != 34)
				{
					if (input[i] == 0)
					{
						ft_putendl_fd("unclosed double quote, invalid input", STDERR_FILENO);
						return (1);
					}
					i++;
				}
			}
		i++;
	}
	}
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_struct	*stru;
	int			i;
	int			j;
	int			k;
	int			len;
	int			exit_code;

	exit_code = 0;
	(void)argc;
	(void)argv;
	stru = ft_calloc(1, sizeof(t_struct));
	stru->ufd_i = 0;
	copy_env(envp, stru);
	signal_handling();
	stru->exit_status = 0; //calloced already
	set("?", "0", stru);
	while (1)
	{
		stru->input = readline("minishell ## ");
		if (!stru->input)
		{
			dprintf(2,"exit\n");
			break ;
		}
		if (strcmp(stru->input, "") == 0)
			continue ;
		if (strncmp(stru->input, "exit ", 5) == 0 || strcmp(stru->input, "exit") == 0)
		{
			if (stru->input[5] != '\0')
			{
				if (stru->input[5] == ' ' || !ft_isdigit(stru->input[5]))
				{
					dprintf(2,"exit: %s numeric argument required\n", stru->input + 5);
					exit_code = 0;
				}
				else
				{
					exit_code = atoi(stru->input + 5);
				}
			}
			dprintf(2,"exit\n");
			exit(exit_code);
		}
		if (quote_errors(stru->input))
		{
			free(stru->input);
			continue ;
		}
		add_history(stru->input);
		stru->input_by_pipes = pipe_split(stru->input);
		i = 0;
		j = 0;
		len = 0;
		while (stru->input_by_pipes[len])
			len++;
		stru->reassembled_commands = ft_calloc((len + 1 + 1), sizeof(char *));
		stru->filefds = ft_calloc((2 * len) + 2, sizeof(int ));
		stru->pids = ft_calloc(len + 1, sizeof(pid_t));
		while (stru->input_by_pipes[i])
		{
			stru->split_by_space = space_split(stru->input_by_pipes[i]);
			open_files(stru, i);
			rem_redir(stru->split_by_space);
			k = 0;
			while (stru->split_by_space[k])
				k++;
			stru->reassembled_commands[j] = line_expansion(concat_strings(stru->split_by_space, k), stru);
			if (stru->reassembled_commands[j] == NULL)
				break ;
			i++;
			j++;
			free_2d(stru->split_by_space);
			free(stru->split_by_space);
		}
		terminate_filefds(stru, i);
		if (stru->reassembled_commands[j] == NULL)
		{
			if (stru->reassembled_commands[0] == NULL)
			{
				continue ;
			}
		}
		stru->reassembled_commands[j] = NULL;
		if (!strcmp(stru->reassembled_commands[0], ""))
		{
			continue ;
		}
		else if (strncmp(stru->reassembled_commands[0], "cd", 2) == 0 && i == 1)
		{
			cd_command(stru, ft_split(stru->reassembled_commands[0], ' ')); // ft_split(stru->reassembled_commands[0], ' ')
		}
		else if (strncmp(stru->reassembled_commands[0], "export", 6) == 0)
		{
			export_command(stru->reassembled_commands[1], stru);
		}
		else
		{
			g_global_sig = 1;
			subprocesses(len, stru->reassembled_commands, envp, stru);
		}
		g_global_sig = 0;
		unset(stru->env_copy, "?");
		stru->str = ft_itoa(stru->exit_status);
		set("?", stru->str, stru);
		free(stru->str);
		//wait(NULL);
		free_loopend(stru, len);

	}
	free_2d(stru->env_copy);
	free(stru->env_copy);
	free(stru->exit_statuses);
	free(stru);
	return (0);
}
