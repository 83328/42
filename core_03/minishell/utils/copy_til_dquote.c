/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_til_dquote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:38:37 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/04 12:07:18 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_til_dquote(char *line, int i);

char	*copy_til_dquote(char *line, int i)
{
	int		n;
	char	*ret;
	int		j;

	j = 0;
	n = count_til_dquote(line, i);
	ret = ft_calloc(sizeof(char), n + 1);
	if (ret == (NULL))
		return (NULL);
	while (line[i] != 34 && line[i] != '\0')
	{
		ret[j] = line[i];
		i++;
		j++;
	}
	if (line[i] == '\0')
	{
		write(1, "error: unclosed double quotes\n", 30);
		free(ret);
		return (NULL);
	}
	ret[j] = '\0';
	return (ret);
}

int	count_til_dquote(char *line, int i)
{
	int	n;

	n = 0;
	while (line[i] != 34 && line[i] != 0)
	{
		i++;
		n++;
	}
	if (line[i - 1] == 0)
	{
		write(1, "error: unclosed double quotes\n", 30);
		return (127);
	}
	return (n);
}
