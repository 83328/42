/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:21:23 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/20 14:28:33 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int unset(char **env_cp, const char *varname)
{
	int i;
	int j;
	int env_count = 0;

	// Count the number of environment variables
	while (env_cp[env_count] != NULL)
		env_count++;
	
	i = 0;
	while (i < env_count)
	{
		if (strncmp(env_cp[i], varname, ft_strlen(varname)) == 0 && env_cp[i][ft_strlen(varname)] == '=') {
			// Free memory for the variable
			free(env_cp[i]);
			// Shift subsequent elements to fill the gap
			j = i;
			while (j < env_count - 1)
			{
				env_cp[j] = env_cp[j + 1];
				j++;
			}
			env_cp[j] = NULL; // Set the last element to NULL
			return (0); // env var existed
		}
		i++;
	}
	return (1); // env var didnt exist
}


/* int unset_command(char *variable)
{
	int *myVariable = (int *)malloc(sizeof(int));
	printf("%s\n", variable);
	if (myVariable == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		return 1;
	}
	*myVariable = 42;
	printf("Before unset: %d\n", *myVariable);
	free(myVariable);
	return 0;
}
 */