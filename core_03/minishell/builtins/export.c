/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:20:13 by alimpens          #+#    #+#             */
/*   Updated: 2024/01/16 15:34:34 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void export_command(char *variable)
{
    // Check if the variable has the format "name=value"
    char *equal_sign = strchr(variable, '=');
    if (equal_sign != NULL)
    {
        // Split the variable into name and value
        *equal_sign = '\0';  // Replace '=' with null terminator
        char *name = variable;
        char *value = equal_sign + 1;

        // Set or modify the environment variable
        if (setenv(name, value, 1) != 0)
        {
            perror("export");
        }
    }
    else
    {
        fprintf(stderr, "Invalid export format. Use 'name=value'.\n");
    }
}
