#include "../minishell.h"

void envp_handling(char *envp[], t_struct *str)
{
	int size;

	size = 0;
	while (envp[size] != NULL)
		{size++;}
	str->envp_copy_size = size + 1;
	str->envp_copy = ft_calloc((size + 1),(sizeof(char*)));
	str->envp_copy = copy_2d(envp, str->envp_copy);
}