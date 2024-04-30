/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_expansion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:34:31 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/30 11:49:47 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*expand_var(char *string, char *value, int start, int var_len);
char	*get_p_var(char *string, int start);
char	*dollars_expansion(char *string, t_struct *stru);

char	*process_quotes(char *cop_line, char *str, t_struct *stru, int *i)
{
	char	*app_str;

	app_str = NULL;
	if (cop_line[*i] == 39 && cop_line[*i + 1])
	{
		(*i)++;
		app_str = copy_til_squote(cop_line, *i);
		*i += ft_strlen(app_str) + 1;
		stru->line_pos += ft_strlen(app_str) + 1;
	}
	else if (cop_line[*i] == 34 && cop_line[*i + 1])
	{
		(*i)++;
		app_str = copy_til_dquote(cop_line, *i);
		*i += ft_strlen(app_str) + 1;
		app_str = dollars_expansion(app_str, stru);
		stru->line_pos += ft_strlen(app_str) + 1;
	}
	str = ft_concat(str, app_str);
	free(app_str);
	return (str);
}

char	*process_no_quotes(char *cop_line, char *str, t_struct *stru, int *i)
{
	char	*app_str;
	int		n;

	n = len_til_quote(cop_line + *i);
	app_str = ft_substr(cop_line, *i, n);
	app_str = dollars_expansion(app_str, stru);
	*i += ft_strlen(app_str) - 1;
	str = ft_concat(str, app_str);
	(*i)++;
	return (str);
}

char	*line_expansion(char *line, t_struct *stru)
{
	char	*cop_line;
	char	*str;
	int		n;
	int		i;

	cop_line = ft_strdup(line);
	i = 0;
	n = 0;
	while (cop_line[i] != 0 && cop_line[i] != 39 && cop_line[i] != 34)
		increment(&n, &i, &(stru->line_pos));
	str = ft_strndup(cop_line, n);
	str = dollars_expansion(str, stru);
	while (cop_line [i] && cop_line[i + 1] != 0)
	{
		if (cop_line[i] == 39 || cop_line[i] == 34)
			str = process_quotes(cop_line, str, stru, &i);
		else if (cop_line[i] != 39 && cop_line[i] != 34)
			str = process_no_quotes(cop_line, str, stru, &i);
	}
	free(line);
	free(cop_line);
	str = replace_dollar_placeholder(str);
	return (str);
}

int	calculate_new_length(char *input_str, char *placeholder, char *dollar_sign)
{
	int		placeholder_count;
	char	*current;

	placeholder_count = 0;
	current = strstr(input_str, placeholder);
	while (current != NULL)
	{
		placeholder_count++;
		current += strlen(placeholder);
		current = strstr(current, placeholder);
	}
	return (strlen(input_str) + (placeholder_count * \
			strlen(dollar_sign)) - (placeholder_count * \
			strlen(placeholder)) + 1);
}

char	*create_new_string(char *input_str,
	char *placeholder, char *dollar_sign, int new_len)
{
	char	*new_str;
	char	*current;
	char	*new_current;
	char	*next;

	new_str = malloc(new_len);
	if (new_str == NULL)
		return (NULL);
	current = input_str;
	new_current = new_str;
	while (1)
	{
		next = strstr(current, placeholder);
		if (next == NULL)
			break ;
		memcpy(new_current, current, next - current);
		new_current += next - current;
		memcpy(new_current, dollar_sign, strlen(dollar_sign));
		new_current += strlen(dollar_sign);
		current = next + strlen(placeholder);
	}
	strcpy(new_current, current);
	return (new_str);
}
