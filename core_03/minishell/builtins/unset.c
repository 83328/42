/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:20:48 by alimpens          #+#    #+#             */
/*   Updated: 2024/01/17 17:27:13 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int unset_command(char *variable)
{
    // Dynamically allocate memory for a variable
    int *myVariable = (int *)malloc(sizeof(int));
    printf("%s\n", variable);
    if (myVariable == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    // Assign a value to the variable
    *myVariable = 42;
    // Print the value before "unsetting"
    printf("Before unset: %d\n", *myVariable);
    // "Unset" the variable by freeing the allocated memory
    free(myVariable);
    // Attempting to access the variable after "unset" may lead to undefined behavior
    // Uncommenting the following line could result in a segmentation fault
    // printf("After unset: %d\n", *myVariable);
    return 0;
}
