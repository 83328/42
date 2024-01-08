/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:44:59 by alimpens          #+#    #+#             */
/*   Updated: 2023/11/24 14:45:37 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void echo_command(const char* input)
{
    // Skip the "echo" part of the input
    const char* echo_args = input + 5;  // Assuming "echo" is followed by a space

    // Print the arguments to the standard output
    printf("%s", echo_args);
}
