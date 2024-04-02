/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_execve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:40:20 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/02 20:12:12 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strichr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}

char	*path_join(char *path, char *executable)
{
	char	*ret;
	int		i;
	int		j;

	ret = malloc(sizeof(char) * (ft_strichr(path, 0) + ft_strichr(executable, 0) + 2));
	i = 0;
	j = 0;
	while (path[j])
		ret[i++] = path[j++];
	ret[i++] = '/';
	j = 0;
	while (executable[j])
		ret[i++] = executable[j++];
	ret[i] = 0;
	return (ret);
}

char	**not_ft_split(char *str, char sep)
{
	char	**tab;
	int		count;
	int		i;
	int		j;

	count = 0;
	j = 0;
	while (str[j])
	{
		if (str[j++] == sep)
			count++;
	}
	tab = malloc(sizeof(char *) * (count + 2));
	tab[count + 1] = NULL;
	i = 0;
	while (i < count + 1)
	{
		j = 0;
		while (str[j] && str[j] != sep)
			j++;
		tab[i++] = ft_strndup(str, j);
		str = str + j + 1;
	}
	return (tab);
}

int	open_file(char *filename, int mode)
{
	if (mode == INFILE)
	{
		if (access(filename, F_OK))
		{
			write(STDERR, "ppp open_file ", 7);
			write(STDERR, filename, ft_strichr(filename, 0));
			write(STDERR, ": No such file or directory\n", 28);
			return (STDIN);
		}
		return (open(filename, O_RDONLY));
	}
	else
		return (open(filename, O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH));
}

char	*get_path(char *command, char **env)
{
	char	*path;
	char	*folder;
	char	*executable;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (command);
	path = env[i] + 5;
	while (path && ft_strichr(path, ':') > -1)
	{
		folder = ft_strndup(path, ft_strichr(path, ':'));
		executable = path_join(folder, command);
		free(folder);
		if (access(executable, F_OK) == 0)
			return (executable);
		free(executable);
		path += ft_strichr(path, ':') + 1;
	}
	return (command);
}

void	mod_execve(char *command, char **env, t_struct *stru)
{
	char	**args;
	char	*path;
	int		i;
	int		result;

	args = not_ft_split(command, ' ');
	i = 0;
	result = 0;
	if (is_builtin(args[0]))
	{
		if (ft_strcmp(args[0], "echo") == 0)
			echo_command(command);
		//if (ft_strcmp(args[0], "cd") == 0)
		//	cd_command(stru, args);
		else if (ft_strcmp(args[0], "pwd") == 0)
			pwd_command();
		else if (ft_strcmp(args[0], "unset") == 0)
		{
			i = 1;
			while (args[i])
			{
				unset(env, args[i]);
				i++;
			}
			return ;
		}
		else if (ft_strcmp(args[0], "env") == 0)
			env_command(stru);
		exit(0);
	}
	else
	{
		if (ft_strichr(args[0], '/') > -1)
			path = args[0];
		else
			path = get_path(args[0], env);
		execve(path, args, env);
		write(STDERR, command, ft_strichr(command, 0));
		write(STDERR, ": command not found\n", 20);
		exit(127);
	}
}
