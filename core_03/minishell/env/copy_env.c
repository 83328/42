#include "../minishell.h"

void copy_env(char *envp[], t_struct *str)
{
	int size;
	int i;

	size = 0;
	i = 0;
	while (envp[size] != NULL)
		size++;
/*
	str->env_copy = malloc(sizeof(char*) * (size + 1));
	if(str->env_copy == NULL)
	{
		perror("malloc");
		exit(1); 
	}
	while(i < size)
	{
		str->env_copy[i] = strdup(envp[i]);
		if(str->env_copy[i] == NULL)
		{
			perror("strdup");
			break;
		}
		i++;
	}
	str->env_copy[i] = NULL;
*/
	str->env_copy_size = size + 1;
	str->env_copy = ft_calloc((size + 1),(sizeof(char*)));
	str->env_copy = copy_2d(envp, str->env_copy);
}
