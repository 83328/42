/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_til_squote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:38:42 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/27 15:09:55 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_til_squote(char *line, int i);

char	*copy_til_squote(char *line, int i)
{
	int		n;
	char	*ret;
	int		j;

	j = 0;
	n = count_til_squote(line, i);
	ret = ft_calloc(sizeof(char), n + 1);
	if (ret == (NULL))
		return (NULL);
	while (line[i] != 39 && line[i] != '\0')
	{
		ret[j] = line[i];
		i++;
		j++;
	}
	if (line[i] == '\0')
	{
		write(1, "error: unclosed single quotes\n", 30);
		free(ret);
		return (NULL);
	}
	ret[j] = '\0';
	return (ret);
}

int	count_til_squote(char *line, int i)
{
	int	n;

	n = 0;
	while (line[i] != 39 && line[i] != 0)
	{
		i++;
		n++;
	}
	if (line[i - 1] == 0)
		perror_exit("1error: unclosed single quotes");
	return (n);
}
