/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_expansion_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:28:41 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/15 10:47:46 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	len_til_quote(char *str)
{
	int	i;

	i = 0;
	while ((str[i] != 39 && str[i] != 34 && str[i] != 0))
		i++;
	return (i);
}

void	count_loop(char *string, int *i, int *var_len)
{
	while (ft_isalnum(string[*i]))
	{
		(*var_len)++;
		(*i)++;
	}
}

void	write_loop(char *string, int *i, int *j, char *p_var)
{
	while (ft_isalnum(string[*i]))
	{
		p_var[*j] = string[*i];
		(*i)++;
		(*j)++;
	}
}

char	*get_p_var(char *string, int start)
{
	char	*p_var;
	int		var_len;
	int		i;
	int		j;

	i = start;
	j = 0;
	var_len = 0;
	count_loop(string, &i, &var_len);
	p_var = malloc(sizeof(char *) * (var_len + 1));
	i = start;
	write_loop(string, &i, &j, p_var);
	p_var[j] = 0;
	return (p_var);
}
