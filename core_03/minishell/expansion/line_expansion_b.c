/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_expansion_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:53:31 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/07 14:18:13 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*expand_string(char *string, char *p_var, char *p_val, int i)
{
	if (p_val != NULL)
	{
		string = expand_var(string, p_val, i, ft_strlen(p_var));
	}
	else
	{
		string = ft_strdup("");
	}
	return (string);
}

char	*process_dollar(char *string, t_struct 
	*stru, int *i, int *still_dollars)
{
	char	*p_var;
	char	*p_val;

	*still_dollars = 1;
	p_var = get_p_var(string, *i + 1);
	p_val = ft_getenv(p_var, stru->env_copy);
	string = expand_string(string, p_var, p_val, *i);
	free(p_var);
	return (string);
}

char	*dollars_expansion(char *string, t_struct *stru)
{
	int		i;
	int		still_dollars;

	i = 0;
	still_dollars = 1;
	while (still_dollars == 1)
	{
		still_dollars = 0;
		i = 0;
		while (string[i] != 0)
		{
			if (string[i] == '$')
			{
				string = process_dollar(string, stru, &i, &still_dollars);
				break ;
			}
			else
				i++;
		}
	}
	return (string);
}
