/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_execve_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgacic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:34:45 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/08 21:34:45 by dgacic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_builtin_command(char **args, char *command, \
			char **env, t_struct *stru)
{
	int	i;

	i = 0;
	if (ft_strcmp(args[0], "echo") == 0)
	{
		echo_command(command);
	}
	else if (ft_strcmp(args[0], "pwd") == 0)
		pwd_command();
	else if (ft_strcmp(args[0], "unset") == 0)
	{
		while (args[i])
		{
			unset(env, args[i]);
			i++;
		}
		return ;
	}
	else if (ft_strcmp(args[0], "env") == 0)
		env_command(stru);
	free_2d(args);
	free(args);
	free_2d(stru->reassembled_commands);
	free(stru->reassembled_commands);
	exit(0);
}

void	handle_other_commands(char **args, char **env, char *command)
{
	char	*path;

	if (ft_strichr(args[0], '/') > -1)
		path = args[0];
	else
		path = get_path(args[0], env);
	execve(path, args, env);
	write(STDERR_FILENO, command, ft_strlen(command));
	write(STDERR_FILENO, ": command not found\n", 20);
	exit(127);
}

void	mod_execve(char *command, char **env, t_struct *stru)
{
	char	**args;

	args = not_ft_split(command, ' ');
	if (is_builtin(args[0]))
	{
		handle_builtin_command(args, command, env, stru);
	}
	else
	{
		handle_other_commands(args, env, command);
	}
}
