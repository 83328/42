/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:18:53 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/24 19:20:31 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	copy_env(char *envp[], t_struct *str)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (envp[size] != NULL)
		size++;
	str->env_copy_size = size + 1;
	str->env_copy = ft_calloc((size + 1),(sizeof(char*)));
	str->env_copy = copy_2d(envp, str->env_copy);
}
