/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:11:00 by alimpens          #+#    #+#             */
/*   Updated: 2024/01/30 14:41:35 by alimpens         ###   ########.fr       */
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

/* #include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_ARGS 100 */

void echo_command_with_split_input(char **split_input, int length)
{
    int ac = 0;
    char *av[MAX_ARGS];
    int i = 0;

    while (i < length)
    {
        if (split_input[i][0] != '\0')
        {
            av[ac] = strdup(split_input[i]);
            if (av[ac] == NULL)
            {
                perror("strdup");
                while (ac > 0)
                {
                    free(av[--ac]);
                }
                exit(EXIT_FAILURE);
            }
            ac++;
        }
        i++;
    }

    echo_command(ac, av);

    int j = 0;
    while (j < ac)
    {
        free(av[j]);
        j++;
    }
}