#include "../minishell.h"

void	resize_env_copy(t_struct *stru);
char	**char2d_realloc(char **ptr, int size, int old_size);

void    export(char *name, char *value, t_struct *stru) //unsure of how to handle memory as of yet
{
	char	*equ;
	char	*val_dup;
	char    *new_var;
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
	stru->env_copy[i] = NULL;
}

/* void	resize_env_copy(t_struct *stru)
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
} */