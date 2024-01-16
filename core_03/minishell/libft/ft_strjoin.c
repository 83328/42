/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgacic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:44:10 by dgacic            #+#    #+#             */
/*   Updated: 2023/01/19 10:44:13 by dgacic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*snew;

	snew = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (snew == 0)
		return (NULL);
	ft_strlcpy(snew, s1, ft_strlen(s1) + 1);
	ft_strlcat(snew, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (snew);
}
