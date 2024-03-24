/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:39:14 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/24 19:43:52 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char    *ft_concat(char *s1, char *s2) //frees mem at s1 and s2, allocates new mem for s1+s2, points s1 at it, returns s1
{
	int		len1;
	int		len2;
	char	*cop_s1;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	cop_s1 = ft_strdup(s1);
	free(s1);
	s1 = (char *)malloc(len1 + len2 + 1);
	if (s1 == NULL)
			perror_exit("Memory allocation failed");
    ft_strcpy(s1, cop_s1);
	free(cop_s1);
    strcat(s1, s2);
	free(s2);
	return (s1);
}
