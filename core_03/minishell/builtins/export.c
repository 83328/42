/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:21:13 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/19 17:39:01 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* void  export_command(char *name, char *value, t_struct *stru)
{
	add_to_envcopy(name, value, stru);
	rebuild_environ(env_copy, size, &environ);
}

void  add_to_envcopy(char *name, char *value, t_struct *stru)
{

	// Allocate new entry
	char *entry = malloc(strlen(name) + strlen(value) + 2);

	// Concatenate name=value
	sprintf(entry, "%s=%s", name, value);

	// Add entry to env_copy
	stru->env_copy[stru->env_size] = entry;

	// Increment size
	stru->env_size++;

}

void  rebuild_environ(char **env_copy, int size, char ***environ_ptr)
{

	// Allocate new environ array
	char **new_env = malloc(sizeof(char*) * (size + 1));
	
	// Copy env_copy to new_env
	char **ptr = env_copy;
	int i = 0;
	while (*ptr != NULL)
	{
		new_env[i] = strdup(*ptr);
		ptr++;
		i++;
	}

	// Set last element to NULL
	new_env[size] = NULL;

	// Update extern variable
	*environ_ptr = new_env;

} */

void	export_command(char *name, char *value, t_struct *stru)
{
		char *new_var;
		int i = 0;

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

printf("environment printout: \n %s\n", stru->env_copy[i]);

	/* char	*equ;
	char	*val_dup;
	char  *new_var;
	int		i;

	equ = ft_strdup("=");
	new_var = ft_strdup(name);
	val_dup = ft_strdup(value);
	new_var = ft_concat(new_var, equ);
	new_var = ft_concat(new_var,val_dup);
	i = 0;
	while(stru->env_copy[i])
	{
		i++;
	//printf("%i",i);
		if (i >= stru->env_copy_size)
			resize_env_copy(stru);
	}
	stru->env_copy[i] = ft_strdup(new_var);
	i++;
	stru->env_copy[i] = NULL; */
}

void	resize_env_copy(t_struct *stru)
{
	int old_size;
	
	old_size = stru->env_copy_size;
	stru->env_copy_size  = stru->env_copy_size * 2;
	stru->env_copy = char2d_realloc(stru->env_copy, stru->env_copy_size, old_size);
}

char	**char2d_realloc(char **ptr, int new_size, int old_size)
{
	char	**ret;

	ret = ft_calloc((new_size + 1),sizeof(char *));

	if (ptr == NULL)
		perror_exit("pointer NULL fail in char2d");
	if (!new_size)
		perror_exit("no size fail in char2d");
	ft_memcpy(ret, ptr, (sizeof(char*)) * (old_size));
	free(ptr);
	return (ret);
} 


/* void export_command(char **args)
{
	int i;
	i = 1;

	while (args[i])
	{
		char *equal_sign = ft_strchr(args[i], '=');
		if (equal_sign)
		{
			*equal_sign = '\0';
			char *name = args[i];
			char *value = equal_sign + 1;
			char *old_value = getenv(name);
			if (old_value)
			{
				if (setenv(name, value, 1) != 0)
					perror("export");
			}
			else
			{
				if (setenv(name, value, 1) != 0)
					perror("export");
			}
		}
		else
		{
			char *name = args[i];
			char *value = getenv(name);
			if (value)
			{
				if (setenv(name, value, 1) != 0)
					perror("export");
			}
			else
			{
				fprintf(stderr, "Invalid export format. Use 'name=value'.\n");
			}
		}
		i++;
	}
} */

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