/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:21:33 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/18 17:33:18 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int echo_command(int ac, char *av[])
{
    int no_newline = 0;
    int i;

    i = 1;
    if (ac > 1 && ft_strcmp(av[1], "-n") == 0)
    {
        no_newline = 1;
        i++;
    }
    while (i < ac)
    {
        printf("%s", av[i]);
        if (i < ac - 1)
            printf(" ");
        i++;
    }
    if (!no_newline)
        printf("\n");
    return (0);
}
