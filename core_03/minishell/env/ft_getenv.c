/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:22:26 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/18 18:34:16 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_getenv(const char *varname, char **env_copy)
{
	char	*current;
	int		i;

	i = 0;
	while (env_copy[i] != NULL) 
	{
		current = env_copy[i];
		if (strncmp(varname, current, strlen(varname)) 
			== 0 && current[strlen(varname)] == '=')
		{
			return (&current[strlen(varname) + 1]);
		}
		i++;
	}
	printStringArray(env_copy);
	return (NULL);
}

/*
// char  *ft_getenv(const char   *varname, char    **env_copy)
// {
//     char* current;

//     int i = 0;
//     while (env_copy[i] != NULL) {
//         current = env_copy[i];
//         int j = 0;
//         while (current[j] != '\0' && current[j] != '=') {
//             j++;
//         }
//         if (current[j] == '=') {
//             current[j] = '\0'; // Null terminate the variable name
//             if (strcmp(varname, current) == 0) {
//                 current[j] = '='; // Restore the string
//                 return &current[j + 1]; // Return the value after the equal sign
//             }
//             current[j] = '='; // Restore the string
//         }
//         i++;
//     }
//     dprintf(2,"testgetenv");
//     printStringArray(env_copy);
//     return NULL; // Variable not found
// }

// char    *ft_getenv(const char* varname, char **env_copy)
// {
//     char* equal_sign;
//     int i = 0;
//     while (env_copy[i] != NULL) {
//         equal_sign = strchr(env_copy[i], '=');
//         if (equal_sign != NULL) {
//             *equal_sign = '\0'; // Split the string at the equal sign
//             if (strcmp(varname, env_copy[i]) == 0)
//             {
//                 *equal_sign = '='; // Restore the string
//                 return equal_sign + 1; // Return the value after the equal sign
//             }
//             *equal_sign = '='; // Restore the string
//         }
//         i++;
//     }
//     dprintf(2,"testgetenv");
//     printStringArray(env_copy);
//     return NULL; // Variable not found
// } */