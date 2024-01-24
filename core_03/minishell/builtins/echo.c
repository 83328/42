/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:11:00 by alimpens          #+#    #+#             */
/*   Updated: 2024/01/18 11:43:27 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int echo_command(int ac, char *av[])
{
    int no_newline = 0;
    int i = 1; // Start from 1 to skip the command itself (echo)

    if (ac > 1 && strcmp(av[1], "-n") == 0)
    {
        no_newline = 1;
        i++; // Skip the -n option in argument printing
    }
    // Print the arguments
    while (i < ac)
    {
        printf("%s", av[i]);
        // Add a space between arguments
        if (i < ac - 1)
            printf(" ");
        i++;  // Increment the loop counter
    }
    // Print a newline character unless -n option is present
    if (!no_newline)
        printf("\n");
    return 0;
}
