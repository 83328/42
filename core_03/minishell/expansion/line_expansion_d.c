/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_expansion_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:53:31 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/05 11:54:30 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	calculate_var_len(char *string, int start)
{
	int		var_len;
	int		i;

	i = start;
	var_len = 0;
	while (string[i] != 0 && (string[i] != ' ' \
		&& string[i] != 't' && string[i] != 'n' \
		&& string[i] != 'r' && string[i] != 'v' \
		&& string[i] != 'f'))
	{
		var_len++;
		i++;
	}
	return (var_len);
}

char	*copy_var(char *p_var, char *string, int start)
{
	int		i;
	int		j;

	i = start;
	j = 0;
	while (string[i] != 0 && (string[i] != ' ' \
		&& string[i] != 't' && string[i] != 'n' \
		&& string[i] != 'r' && string[i] != 'v' \
		&& string[i] != 'f'))
	{
		p_var[j] = string[i];
		i++;
		j++;
	}
	p_var[j] = 0;
	return (p_var);
}

char	*get_p_var(char *string, int start)
{
	char	*p_var;
	int		var_len;

	var_len = calculate_var_len(string, start);
	p_var = malloc(sizeof(char *) * (var_len + 1));
	p_var = copy_var(p_var, string, start);
	return (p_var);
}
