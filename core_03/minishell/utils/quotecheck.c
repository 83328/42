/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotecheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:31:33 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/12 13:56:58 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_unclosed_quote(char *input, char quote_type, const char *error_message)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == quote_type)
		{
			i++;
			while (input[i] != quote_type)
			{
				if (input[i] == '\0')
				{
					write(STDERR_FILENO, error_message \
					, ft_strlen(error_message));
					return (1);
				}
				i++;
			}
		}
		i++;
	}
	return (0);
}

int	check_quotes(char *input, int *i, char quote_type, char *error_message)
{
	(*i)++;
	while (input[*i] != quote_type)
	{
		if (input[*i] == 0)
		{
			write(2, error_message, ft_strlen(error_message));
			return (-1);
		}
		(*i)++;
	}
	return (0);
}

int	quote_errors(char *input)
{
	int	i;
	int	quote_ret;

	i = 0;
	while (input[i] != 0)
	{
		if (input[i] == 34 || input[i] == 39)
		{
			if (input[i] == 34)
				quote_ret = check_quotes(input, &i, \
					34, "unclosed double quotes\n");
			else if (input[i] == 39)
				quote_ret = check_quotes(input, &i, \
					39, "unclosed single quotes\n");
			i++;
		}
		else
			i++;
	}
	if (quote_ret == -1)
	{
		return (1);
	}
	return (0);
}

int	check_unclosed_double_quotes(char *input, int i)
{
	if (input[i] == 34)
	{
		i++;
		while (input[i] != 34)
		{
			if (input[i] == 0)
			{
				ft_putendl_fd("unclosed double quote", STDERR_FILENO);
				return (1);
			}
			i++;
		}
	}
	return (0);
}
