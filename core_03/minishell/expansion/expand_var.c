/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:40:22 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/15 11:34:59 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	write_til_start(int *i, int *start, char *cop_line, char *str)
{
	while (*i < *start)
	{
		str[*i] = cop_line[*i];
		(*i)++;
	}
}

void	write_val(int *i, int *j, char *str, char *value)
{
	str[*i] = value[*j];
	(*i)++;
	(*j)++;
}

char	*expand_var(char *str, char *value, int start, int var_len)
{
	int		i;
	int		j;
	int		val_len;
	char	*cop_line;

	val_len = ft_strlen(value);
	i = 0;
	j = 0;
	cop_line = ft_strdup(str);
	free(str);
	str = malloc(sizeof(char) * (ft_strlen(cop_line) + val_len + 1));
	write_til_start(&i, &start, cop_line, str);
	while (i < val_len + start)
		write_val(&i, &j, str, value);
	j = 0;
	while (j < (int)((ft_strlen(cop_line) - var_len - 1 - start)))
	{
		str[i] = cop_line[j + start + var_len + 1];
		i++;
		j++;
	}
	str[i] = 0;
	return (str);
}

void	increment(int *n, int *i, int *pos)
{
	(*n)++;
	(*i)++;
	(pos)++;
}
