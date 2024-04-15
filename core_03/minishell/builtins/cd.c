/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:35:14 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/11 14:00:15 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	update_env_var(char *var, char *new_value, char **envp)
{
	int		i;
	char	*entry;

	i = 0;
	while (envp[i] != NULL)
	{
		entry = envp[i];
		if (ft_strncmp(entry, var, ft_strlen(var)) == 0)
		{
			free(entry);
			envp[i] = ft_strjoin(var, new_value);
			if (envp[i] == NULL)
			{
				return ;
			}
		}
		i++;
	}
}

/* void	handle_cd(char *old_pwd, char *home_path, char *args[])
{
	char	*last_slash;

	last_slash = strrchr(old_pwd, '/');
	if (args[1] == NULL || ft_strcmp(args[1], "..") == 0)
	{
		if (last_slash != NULL)
			*last_slash = '\0'; 
		chdir(old_pwd);
	}
	else if (ft_strcmp(args[1], "~") == 0)
		chdir(home_path);
	else
		chdir(args[1]);
}

void	cd_command(t_struct *stru, char *args[])
{
	char	*old_pwd;
	char	*home_path;
	char	*current_dir;
	char	*check;

	old_pwd = getcwd(NULL, 0);
	home_path = ft_getenv("HOME", stru->env_copy);
	current_dir = getcwd(NULL, 0);
	handle_cd(old_pwd, home_path, args);
	set("PWD", current_dir, stru);
	check = ft_getenv("PWD",stru->env_copy);
	if (ft_strcmp(check, old_pwd) == 0)
	{
		write (2, "cd error, dir did not exist\n", 29);
		stru->exit_status = 1;
	}
	free(old_pwd);
	free(current_dir);
} */

int	handle_cd(char *old_pwd, char *home_path, char *args[])
{
	int	ret;

	if (args[1] == NULL)
		ret = chdir(old_pwd);
	else if (ft_strcmp(args[1], "~") == 0)
		ret = chdir(home_path);
	else
		ret = chdir(args[1]);
	return (ret);
}

void	check_directory_exists(t_struct *stru, char *args[])
{
	if (args[1] && strcmp(args[1], "~") != 0 && access(args[1], F_OK) == -1)
	{
		write(2, "cd: No such file or directory: ", 31);
		write(2, args[1], strlen(args[1]));
		write(2, "\n", 1);
		stru->exit_status = 1;
		exit(1);
	}
}

void	cd_command(t_struct *stru, char *args[])
{
	char	*old_pwd;
	char	*home_path;
	char	*current_dir;
	int		ret;

	old_pwd = getcwd(NULL, 0);
	home_path = ft_getenv("HOME", stru->env_copy);
	check_directory_exists(stru, args);
	ret = handle_cd(old_pwd, home_path, args);
	current_dir = getcwd(NULL, 0);
	set("PWD", current_dir, stru);
	if (ret == -1)
	{
		write(2, "cd: error, directory change failed\n", 35);
		stru->exit_status = 1;
	}
	else if (strcmp(old_pwd, current_dir) != 0)
	{
		write(1, "Changed directory to: ", 22);
		write(1, current_dir, strlen(current_dir));
		write(1, "\n", 1);
	}
	free(old_pwd);
	free(current_dir);
}

/* void	cd_command(t_struct *stru, char *args[])
{
	char	*old_pwd;
	char	*home_path;
	char	*current_dir;
	int		ret;

	old_pwd = getcwd(NULL, 0);
	home_path = ft_getenv("HOME", stru->env_copy);
	ret = handle_cd(old_pwd, home_path, args);
	current_dir = getcwd(NULL, 0);
	set("PWD", current_dir, stru);
	if (ret == -1)
	{
		write(2, "cd: error, directory change failed\n", 35);
		stru->exit_status = 1;
	}
	else
	{
		if (strcmp(old_pwd, current_dir) != 0)
		{
			write(1, "Changed directory to: ", 22);
			write(1, current_dir, ft_strlen(current_dir));
			write(1, "\n", 1);
		}
	}
	free(old_pwd);
	free(current_dir);
} */

/* void	cd_command(t_struct *stru, char *args[])
{
	char	*old_pwd;
	char	*home_path;
	char	*last_slash;
	char	*current_dir;
	char	*check;

	old_pwd = getcwd(NULL, 0);
	home_path = ft_getenv("HOME", stru->env_copy);
	last_slash = strrchr(old_pwd, '/');
	current_dir = getcwd(NULL, 0);
	if (args[1] == NULL || ft_strcmp(args[1], "..") == 0)
	{
		if (last_slash != NULL)
			*last_slash = '\0'; 
		chdir(old_pwd);
	}
	else if (ft_strcmp(args[1], "~") == 0)
		chdir(home_path);
	else
		chdir(args[1]);
	set("PWD", current_dir, stru);
	check = ft_getenv("PWD",stru->env_copy);
	if (ft_strcmp(check, old_pwd) == 0)
	{
		write (2, "cd error, dir did not exist\n", 29);
		stru->exit_status = 1;
	}
	free(old_pwd);
	free(current_dir);
} */
