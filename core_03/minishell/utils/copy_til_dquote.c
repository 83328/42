/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_til_dquote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 06:37:25 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/07 16:08:39 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_til_dquote(char *line, int i);

/* char	*copy_til_dquote(char *line, int i)
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
} */

char	*copy_til_dquote(char *line, int i)
{
	int		n;
	char	*ret;
	int		j;

	j = 0;
	n = count_til_dquote(line, i);
	ret = ft_calloc(sizeof(char), n + 1);
	if (ft_strchr(&line[i], '"') == NULL)
		return (NULL);
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
