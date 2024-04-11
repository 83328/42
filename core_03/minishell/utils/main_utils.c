/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:31:33 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/10 22:48:46 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_struct	*startup(int argc, char *argv[], char *envp[], t_struct *stru)
{
	(void)argc;
	(void)argv;
	stru = ft_calloc(1, sizeof(t_struct));
	stru->ufd_i = 0;
	copy_env(envp, stru);
	signal_handling();
	stru->exit_status = 0;
	set("?", "0", stru);
	stru->exit_code = 0;
	return (stru);
}

void	builtin_or_commands(t_struct *stru, t_vars *vars)
{
	char	**split_command;

	if (ft_strncmp(stru->reassembled_commands[0], "cd", 2) == 0 && vars->i == 1)
		process_command(stru, 1);
	else if (ft_strncmp(stru->reassembled_commands[0], "export", 6) == 0)
		process_command(stru, 2);
	else if (ft_strncmp(stru->reassembled_commands[0], "unset", 5) == 0)
	{
		split_command = NULL;
		split_command = ft_split(stru->reassembled_commands[0], ' ');
		unset(stru->env_copy, split_command[1]);
		free(split_command);
		return ;
	}
	else
	{
		g_global_sig = 1;
		subprocesses(vars->len, stru->reassembled_commands, stru);
	}
	g_global_sig = 0;
	unset(stru->env_copy, "?");
	stru->str = ft_itoa(stru->exit_status);
	set("?", stru->str, stru);
}

/* void	builtin_or_commands(t_struct *stru, t_vars *vars)
{
	char	**split_command;

	if (ft_strncmp(stru->reassembled_commands[0], "cd", 2) == 0 && vars->i == 1)
	{
		split_command = ft_split(stru->reassembled_commands[0], ' ');
		cd_command(stru, split_command);
		free(split_command);
	}
	else if (ft_strncmp(stru->reassembled_commands[0], "export", 6) == 0)
	{
		split_command = ft_split(stru->reassembled_commands[0], ' ');
		export_command(stru, split_command);
		free(split_command);
	}
	else if (ft_strncmp(stru->reassembled_commands[0], "unset", 5) == 0)
	{
		split_command = ft_split(stru->reassembled_commands[0], ' ');
		unset(stru->env_copy, split_command[1]);
		free(split_command);
		return ;
	}
	else
	{
		g_global_sig = 1;
		subprocesses(vars->len, stru->reassembled_commands, stru);
	}
	g_global_sig = 0;
	unset(stru->env_copy, "?");
	stru->str = ft_itoa(stru->exit_status);
	set("?", stru->str, stru);
} */

/* void	exit_parse(t_struct *stru)
{
	if (ft_strncmp(stru->input, "exit ", 5) == 0 \
	|| ft_strcmp(stru->input, "exit") == 0)
	{
		if (stru->input[5] != '\0')
		{
			if (stru->input[5] == ' ' || !ft_isdigit(stru->input[5]))
			{
				dprintf(2, "exit: %s numeric argument required\n" \
				, stru->input + 5);
				stru->exit_code = 0;
			}
			else
				stru->exit_code = ft_atoi(stru->input + 5);
		}
		dprintf(2, "exit\n");
		exit(stru->exit_code);
	}
} */

void	handle_exit_error(t_struct *stru, int space_count)
{
	if (space_count > 0)
	{
		write(2, "exit: too many arguments\n", 24);
		stru->exit_code = 1;
		return ;
	}
	write(2, " numeric argument required\n", 27);
	stru->exit_code = 0;
}

void	check_exit_args(t_struct *stru, char *arg)
{
	int	i;
	int	space_count;

	i = 0;
	space_count = 0;
	while (arg[i] != '\0')
	{
		if (!ft_isdigit(arg[i]))
		{
			if (arg[i] == ' ')
			{
				if (arg[i + 1] == '\0')
					break ;
				space_count++;
			}
			handle_exit_error(stru, space_count);
			break ;
		}
		i++;
	}
	if (ft_isdigit(arg[0]) && space_count == 0)
		stru->exit_code = ft_atoi(arg);
}

void	exit_parse(t_struct *stru)
{
	char	*arg;

	if (ft_strncmp(stru->input, "exit ", 5) == 0 \
	|| ft_strcmp(stru->input, "exit") == 0)
	{
		arg = stru->input + 5;
		while (*arg == ' ')
			arg++;
		check_exit_args(stru, arg);
		write(2, "exit\n", 6);
		exit(stru->exit_code);
	}
}
