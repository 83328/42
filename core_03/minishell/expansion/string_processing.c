/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_processing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:43:55 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/30 23:37:11 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*inner_loop(char *string, t_struct *stru, int *i);

char	*replace_dollar_placeholder(char *input_str)
{
	char	*placeholder;
	char	*dollar_sign;
	int		new_len;
	char	*new_str;

	placeholder = "DOLLA_SIGN_PLACEHOLDER";
	dollar_sign = "$";
	new_len = calculate_new_length(input_str, placeholder,
			dollar_sign);
	if (new_len < 1)
		return (input_str);
	new_str = create_new_string(input_str, placeholder,
			dollar_sign, new_len);
	free(input_str);
	return (new_str);
}

int	contains_dollars(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] == '$')
		{
			return (1);
		}
		i++;
	}
	return (0);
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
		if (contains_dollars(string))
			still_dollars = 1;
		i = 0;
		string = inner_loop(string, stru, &i);
	}
	return (string);
}

char	*remove_var(char *str, char *value, int start, int var_len)
{
	int		i;
	int		j;
	int		val_len;
	char	*cop_line;

	if (var_len == 0)
		value = ft_strdup("DOLLA_SIGN_PLACEHOLDER");
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
	blocktest(str, value, cop_line, i);
	return (str);
}

char	*inner_loop(char *string, t_struct *stru, int *i)
{
	char	*p_var;
	char	*p_val;

	while (string && string[*i] != 0)
	{
		if (string[*i] == '$')
		{
			p_var = get_p_var(string, *i + 1);
			p_val = ft_getenv(p_var, stru->env_copy);
			if (p_val != NULL)
			{
				string = expand_var(string, p_val, *i, ft_strlen(p_var));
				free (p_var);
				break ;
			}
			string = remove_var(string, NULL, *i, ft_strlen(p_var));
			free (p_var);
			break ;
		}
		else
			(*i)++;
	}
	return (string);
}
