/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:11:00 by alimpens          #+#    #+#             */
/*   Updated: 2024/01/15 16:09:02 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int is_quote(char c)
{
    return c == 39 || c == 34;// 39 is the ASCII code for single quote (') and 34 is for double quote (")
}

void process_quotes(char *token)
{
//    printf("Before processing quotes: %s\n", token);
    int len = strlen(token);
    if (len > 1 && (token[0] == '\'' || token[0] == '\"') && token[0] == token[len - 1])
    {
        // Remove quotes from the token
        memmove(token, token + 1, len - 2);
        token[len - 2] = '\0';
    }
//    printf("After processing quotes: %s\n", token);
}

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
        process_quotes(av[i]);
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
