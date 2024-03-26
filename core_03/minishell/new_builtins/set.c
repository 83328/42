#include "../minishell.h"

void	set(char *name, char *value, t_struct *stru) //unsure of how to handle memory as of yet
{
	char	*equ;
	char	*val_dup;
	char	*new_var;
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
		if (i >= stru->env_copy_size)
			resize_env_copy(stru);
	}
	stru->env_copy[i] = ft_strdup(new_var);
	i++;
	stru->env_copy[i] = 0;
}
