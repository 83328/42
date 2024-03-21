#include "../minishell.h"

void copy_env(char *envp[], t_struct *str)
{
	int size;

	size = 0;
	while (envp[size] != NULL)
		{size++;}
	str->env_copy_size = size + 1;
	str->env_copy = ft_calloc((size + 1),(sizeof(char*)));
	str->env_copy = copy_2d(envp, str->env_copy);
}