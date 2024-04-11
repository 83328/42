/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgacic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:32:03 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/08 21:32:03 by dgacic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_concat(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*cop_s1;

	if (!s1)
		return (s2);
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

/* char	*ft_concat(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*result;

	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc(len1 + len2 + 1);
	if (result == NULL)
		perror_exit("Memory allocation failed");
	ft_strcpy(result, s1);
	strcat(result, s2);
	return (result);
} */
