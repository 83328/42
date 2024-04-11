/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:07:23 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/10 17:30:28 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	write_quotes(char *new_str, size_t *j, int quote_count)
{
	if (quote_count % 2 != 0)
	{
		while (quote_count-- > 0)
			new_str[(*j)++] = 34;
	}
	else if (quote_count % 2 == 0)
	{
		new_str[(*j)++] = 34;
		new_str[(*j)++] = 34;
	}
}

void	process_string(char *str, char *new_str, size_t *i, size_t *j)
{
	int	quote_count;

	while (str[*i] != '\0')
	{
		if (str[*i] != 34)
		{
			new_str[*j] = str[*i];
			(*i)++;
			(*j)++;
			continue ;
		}
		quote_count = 0;
		while (str[*i] == 34)
		{
			quote_count++;
			(*i)++;
		}
		write_quotes(new_str, j, quote_count);
		quote_count = 0;
	}
}

char	*allocate_memory(size_t len)
{
	char	*new_str;

	new_str = (char *)malloc((len + 1) * sizeof(char));
	if (new_str == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	return (new_str);
}

char	*reduce_quotes(char *str)
{
	size_t	len;
	char	*new_str;
	size_t	i;
	size_t	j;

	len = ft_strlen(str);
	new_str = allocate_memory(len);
	i = 0;
	j = 0;
	process_string(str, new_str, &i, &j);
	new_str[j] = '\0';
	return (new_str);
}

/* char	*reduce_quotes(char *str)
{
	size_t	len;
	char	*new_str;
	size_t	i;
	size_t	j;
	int		quote_count;

	len = ft_strlen(str);
	new_str = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	j = 0;
	quote_count = 0;
	if (new_str == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	while (str[i] != '\0')
	{
		if (str[i] != 34)
		{
			new_str[j] = str[i];
			i++;
			j++;
			continue ;
		}
		while (str[i] == 34)
		{
			quote_count++;
			i++;
		}
		if (quote_count % 2 != 0)
		{
			while (quote_count-- > 0)
				new_str[j++] = 34;
		}
		else if (quote_count % 2 == 0)
		{
			new_str[j++] = 34;
			new_str[j++] = 34;
		}
		quote_count = 0;
	}
	new_str[j] = '\0';
	return (new_str);
} */