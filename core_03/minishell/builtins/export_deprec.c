/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_deprec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:52:56 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/21 16:35:09 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		is_valid_identifier(char *s);
void	add_to_env(t_struct *stru, char *new_var);
void	resize_env_copy(t_struct *stru);
char	**char2d_realloc(char **ptr, int new_size, int old_size);

void export_command(char *name, char *value, t_struct *stru)
{
	char *equ = ft_strdup("=");
	char *new_var = ft_strjoin(name, equ);

	if (value)
	{
		new_var = ft_strjoin(new_var, value);
	}

	// Check if new_var is a valid identifier
	if(!is_valid_identifier(new_var))
	{
		printf("Not a valid identifier: %s\n", new_var); 
		return;
	}
// Search for name in env_copy
	int i = 0;
	while(stru->env_copy[i])
	{
	if (ft_strncmp(name, stru->env_copy[i], ft_strlen(name)) == 0)
	{
		// Found - update value
		free(stru->env_copy[i]);
		stru->env_copy[i] = ft_strdup(new_var);
		return;
	}
	i++;
	}
	// Not found - add new variable
	add_to_env(stru, new_var); 
}

// Helper functions
int is_valid_identifier(char *s)
{
	if (!s || !*s)
		return 0;
	if (!(ft_isalpha(*s) || *s == '_'))
		return 0;
	while (*s)
	{
		if(!(ft_isalnum(*s) || *s == '_'))
		return 0;
		s++; 
	}
	return 1;
// Check if s contains only valid identifier chars
// Return 1 if valid, 0 otherwise
}

void add_to_env(t_struct *stru, char *new_var)
{
	// Allocate new env_copy array
	int old_size = stru->env_copy_size;
	stru->env_copy_size++;
	char **new_env = ft_calloc(stru->env_copy_size, sizeof(char*));

	// Copy old env to new array
	ft_memcpy(new_env, stru->env_copy, old_size * sizeof(char*));

	// Add new variable
	new_env[old_size-1] = ft_strdup(new_var);
	new_env[old_size] = NULL;

	// Free old env and update stru
	free(stru->env_copy);
	stru->env_copy = new_env;
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
