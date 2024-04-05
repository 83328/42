/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotecheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgacic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 06:37:25 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/05 06:37:25 by dgacic           ###   ########.fr       */
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

int	quote_errors(char *input)
{
	if (is_unclosed_quote(input, '\'', "unclosed single quote\n"))
		return (1);
	if (is_unclosed_quote(input, '"', "unclosed double quote\n"))
		return (1);
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
