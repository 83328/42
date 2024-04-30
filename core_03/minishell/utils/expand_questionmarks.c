/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_questionmarks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:31:48 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/30 16:34:21 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*malloc_and_check(int len)
{
	char	*new_str;

	new_str = (char *)malloc((len + 1) * sizeof(char));
	if (new_str == NULL)
	{
		fprintf(stderr, "Memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}
	return (new_str);
}

void	expand_dollar_question(t_expansion *exp)
{
	size_t	k;

	k = 0;
	while (exp->numerical_string[k] != '\0')
		exp->new_str[exp->j++] = exp->numerical_string[k++];
	exp->i += 2;
}

void	expand_regular_char(t_expansion *exp)
{
	exp->new_str[exp->j++] = exp->str[exp->i++];
}

char	*expand_questionmarks(char *str, const char *numerical_string)
{
	t_expansion	exp;

	exp.str = str;
	exp.numerical_string = numerical_string;
	exp.len = ft_strlen(str);
	if (exp.len < 1)
		return (str);
	exp.new_str = malloc_and_check(exp.len);
	exp.i = 0;
	exp.j = 0;
	while (exp.i < exp.len)
	{
		if (exp.str[exp.i] == '$' && exp.str[exp.i + 1] 
			== '?' && exp.i + 1 < exp.len)
			expand_dollar_question(&exp);
		else
			expand_regular_char(&exp);
	}
	exp.new_str[exp.j] = '\0';
	free(str);
	return (exp.new_str);
}

/* char	*expand_questionmarks(char *str, const char *numerical_string)
{
	size_t	len;
	size_t	j;
	size_t	i;
	char	*new_str;
	size_t	k;

	len = ft_strlen(str);
	if (len < 1)
		return (str);
	new_str = malloc_and_check(len);
	i = 0;
	j = 0;
	while (i < len)
	{
		if (str[i] == '$' && str[i + 1] == '?' && i + 1 < len)
		{
			k = 0;
			while (numerical_string[k] != '\0')
				new_str[j++] = numerical_string[k++];
			i += 2;
		}
		else
			new_str[j++] = str[i++];
	}
	new_str[j] = '\0';
	free(str);
	return (new_str);
} */
