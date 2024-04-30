/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:32:03 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/30 16:25:38 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* char	*ft_concat(char *s1, char *s2)
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
} */

char	*ft_concat_free(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*result;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc(len1 + len2 + 1);
	if (result == NULL)
		perror_exit("Memory allocation failed");
	if (len1 > 0)
		ft_strcpy(result, s1);
	if (len2 > 0)
		ft_strcat(result, s2);
	free(s1);
	free(s2);
	return (result);
}

char	*ft_concat(char *s1, const char *s2)
{
	int		len1;
	int		len2;
	char	*result;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc(len1 + len2 + 1);
	if (result == NULL)
		perror_exit("Memory allocation failed");
	if (len1 > 0)
		ft_strcpy(result, s1);
	if (len2 > 0)
		ft_strcat(result, s2);
	ft_strcpy(result, s1);
	ft_strcat(result, s2);
	return (result);
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
