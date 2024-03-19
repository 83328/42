/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:21:00 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/18 17:35:54 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	update_env_var(char *var, char *new_value, char **envp)
{
	int		i;
	char	*entry;

	i = 0;
	while ((entry = envp[i]) != NULL)
	{
		if (ft_strncmp(entry, var, ft_strlen(var)) == 0)
		{
			printf("File path-b: %s\n", entry);
			free(entry);
			envp[i] = ft_strjoin(var, new_value);
			printf("File path-a: %s\n", envp[i]);
		}
		i++;
	}
}

void	cd_command(t_struct *stru, char *args[])
{
	char	*old_pwd;

	old_pwd = getcwd(NULL, 0);
	if (args[1] == NULL || strcmp(args[1], "..") == 0)
	{
		char	*last_slash = strrchr(old_pwd, '/');
		if (last_slash != NULL)
		{
			*last_slash = '\0'; 
		}
		chdir(old_pwd);
	}
	else
	{
		chdir(args[1]);
	}
	char	*current_dir = getcwd(NULL, 0);
	update_env_var("PWD", current_dir, stru->env_copy);
	free(old_pwd);
	free(current_dir);
}
