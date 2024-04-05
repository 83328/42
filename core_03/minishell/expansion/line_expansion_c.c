/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_expansion_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:53:31 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/05 11:53:48 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*copy_start_to_str(t_expansion *exp)
{
	int		i;

	i = 0;
	while (i < exp->start)
	{
		exp->str[i] = exp->cop_line[i];
		i++;
	}
	return (exp->str);
}

char	*copy_value_to_str(t_expansion *exp, char *value, int val_len)
{
	int		i;
	int		j;

	i = exp->start;
	j = 0;
	while (i < val_len + exp->start)
	{
		exp->str[i] = value[j];
		i++;
		j++;
	}
	return (exp->str);
}

char	*copy_remaining_to_str(t_expansion *exp)
{
	int		i;
	int		j;

	i = exp->start + ft_strlen(exp->str);
	j = 0;
	while (j < (int)((ft_strlen(exp->cop_line) - 
			exp->var_len - 1 - exp->start)))
	{
		exp->str[i] = exp->cop_line[j + exp->start + exp->var_len + 1];
		i++;
		j++;
	}
	exp->str[i] = 0;
	return (exp->str);
}

char	*expand_var(char *str, char *value, int start, int var_len)
{
	int			val_len;
	char		*cop_line;
	t_expansion	exp;

	val_len = ft_strlen(value);
	cop_line = ft_strdup(str);
	free(str);
	str = malloc(sizeof(char) * (ft_strlen(cop_line) + val_len + 1));
	exp.str = str;
	exp.cop_line = cop_line;
	exp.start = start;
	exp.var_len = var_len;
	str = copy_start_to_str(&exp);
	str = copy_value_to_str(&exp, value, val_len);
	str = copy_remaining_to_str(&exp);
	free(cop_line);
	return (str);
}
