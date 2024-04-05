/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:21:00 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/04 14:31:34 by alimpens         ###   ########.fr       */
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

void	cd_command(t_struct *stru, char *args[])
{
	char	*old_pwd;
	char	*home_path;
	char	*last_slash;
	char	*current_dir;

	old_pwd = getcwd(NULL, 0);
	home_path = getenv("HOME");
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
	update_env_var("PWD", current_dir, stru->env_copy);
	free(old_pwd);
	free(current_dir);
}
