/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 23:33:41 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/30 23:40:26 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	blockout0(int *i, char *value, char *cop_line, char *str)
{
	str[*i] = 0;
	if (value != NULL)
		free(value);
	free(cop_line);
}

char	*blockout2(char *cop_line, char *str, int *val_len)
{
	cop_line = ft_strdup(str);
	free(str);
	str = malloc(sizeof(char) * (ft_strlen(cop_line) + *val_len + 1));
	return (cop_line);
}

void	blocktest(char *str, char *value, char *cop_line, int i)
{
	*(str + i) = 0;
	free(cop_line);
	if (value != NULL)
		free(value);
}

void	free_mult(t_struct *stru)
{
	free_2d(stru->input_by_pipes);
	free(stru->input_by_pipes);
	free(stru->filefds);
	free(stru->pids);
}
