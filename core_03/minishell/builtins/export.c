/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:21:13 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/22 17:32:10 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	export_command(char *name, char *value, t_struct *stru)
{
	char *new_var;
	int i;

	i = 0;
	new_var = ft_strjoin(ft_strjoin(name, "="), value);
	if (!new_var)
	{
		fprintf(stderr, "Memory allocation failed\n");
		return;
	}
	while (stru->env_copy[i])
	{
		i++;
		if (i >= stru->env_copy_size - 1)
		{
			resize_env_copy(stru);
			if (!stru->env_copy)
			{
				free(new_var);
				fprintf(stderr, "Memory allocation failed\n");
				return;
			}
		}
	}
	stru->env_copy[i] = new_var;
	stru->env_copy[i + 1] = NULL;
	//printf("environment printout: \n %s\n", stru->env_copy[i]);
}

void	resize_env_copy(t_struct *stru)
{
	int old_size;
	int i;
	
	old_size = stru->env_copy_size;
	stru->env_copy_size  = stru->env_copy_size * 2;
	stru->env_copy = char2d_realloc(stru->env_copy, stru->env_copy_size, old_size);
	i = old_size;
	while (i < stru->env_copy_size)
	{
		stru->env_copy[i] = NULL;
		i++;
	}
}

char	**char2d_realloc(char **ptr, int new_size, int old_size)
{
	char	**ret;
	int		i;

	i = 0;
	ret = ft_calloc(new_size, sizeof(char *));
	if (ptr == NULL)
		perror_exit("pointer NULL fail in char2d");
	if (!new_size)
		perror_exit("no size fail in char2d");
//	ft_memcpy(ret, ptr, (sizeof(char*)) * (old_size));
	while(i < old_size)
	{
		ret[i] = ptr[i];
		i++;
	}
	if (i < new_size)
	free(ptr);
	return (ret);
}

/* 
alimpens@c4c2c5:~/Documents/Core/Core_03/MS_240318/builtins/hello$ export hello=alimpens
alimpens@c4c2c5:~/Documents/Core/Core_03/MS_240318/builtins/hello$ echo $hello
alimpens
alimpens@c4c2c5:~/Documents/Core/Core_03/MS_240318/builtins/hello$ export hello=minishell
alimpens@c4c2c5:~/Documents/Core/Core_03/MS_240318/builtins/hello$ echo $hell

alimpens@c4c2c5:~/Documents/Core/Core_03/MS_240318/builtins/hello$ echo $hello
minishell
alimpens@c4c2c5:~/Documents/Core/Core_03/MS_240318/builtins/hello$ env | grep hell
PWD=/home/alimpens/Documents/Core/Core_03/MS_240318/builtins/hello
hello=minishell
OLDPWD=/home/alimpens/Documents/Core/Core_03/MS_240318/builtins/hello
alimpens@c4c2c5:~/Documents/Core/Core_03/MS_240318/builtins/hello$ pwd
/home/alimpens/Documents/Core/Core_03/MS_240318/builtins/hello
alimpens@c4c2c5:~/Documents/Core/Core_03/MS_240318/builtins/hello$ cd ..
alimpens@c4c2c5:~/Documents/Core/Core_03/MS_240318/builtins$ cd..
cd..: command not found
alimpens@c4c2c5:~/Documents/Core/Core_03/MS_240318/builtins$ cd ..
alimpens@c4c2c5:~/Documents/Core/Core_03/MS_240318$ pwd
/home/alimpens/Documents/Core/Core_03/MS_240318
alimpens@c4c2c5:~/Documents/Core/Core_03/MS_240318$ ./minishell 
 */

/* #include "../minishell.h"

void	export_command(char *name, char *value, t_struct *stru)
{
	char *new_var;
	int i;

	i = 0;
	new_var = ft_strjoin(ft_strjoin(name, "="), value);
	if (!new_var)
	{
		fprintf(stderr, "Memory allocation failed\n");
		return;
	}
	while (stru->env_copy[i])
	{
		i++;
		if (i >= stru->env_copy_size)
		{
			resize_env_copy(stru);
			if (!stru->env_copy)
			{
				free(new_var);
				fprintf(stderr, "Memory allocation failed\n");
				return;
			}
		}
	}
	stru->env_copy[i] = new_var;
	stru->env_copy[i + 1] = NULL;
	//printf("environment printout: \n %s\n", stru->env_copy[i]);
}

void	resize_env_copy(t_struct *stru)
{
	int old_size;
	int i;
	
	old_size = stru->env_copy_size;
	stru->env_copy_size  = stru->env_copy_size * 2;
	stru->env_copy = char2d_realloc(stru->env_copy, stru->env_copy_size, old_size);
	i = old_size;
	while (i < stru->env_copy_size)
	{
		stru->env_copy[i] = NULL;
		i++;
	}
}

char	**char2d_realloc(char **ptr, int new_size, int old_size)
{
	char	**ret;
	int		i;

	i = 0;
	ret = ft_calloc((new_size + 1),sizeof(char *));
	if (ptr == NULL)
		perror_exit("pointer NULL fail in char2d");
	if (!new_size)
		perror_exit("no size fail in char2d");
//	ft_memcpy(ret, ptr, (sizeof(char*)) * (old_size));
	while(i < old_size)
	{
		ret[i] = ptr[i];
		i++;
	}
	free(ptr);
	return (ret);
} */