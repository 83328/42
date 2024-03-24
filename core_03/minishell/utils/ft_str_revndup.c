/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_revndup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:38:46 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/24 19:38:47 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char    *ft_str_revndup(const char *str, int n)
{
    char    *new_str;
    int     i;

    i = 0;
    new_str = malloc(sizeof(char) * (ft_strlen(str) - n));
    while (str[n] != 0)
    {
        new_str[i] = str[n];
        n++;
        i++;
    }
    new_str[i] = 0;
    return (new_str);
}