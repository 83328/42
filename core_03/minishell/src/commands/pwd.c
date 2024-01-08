/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:45:09 by alimpens          #+#    #+#             */
/*   Updated: 2023/11/24 13:42:58 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void pwd_command()
{
    char* current_directory = getcwd(NULL, 0);

    if (current_directory == NULL)
    {
        perror("getcwd");
    } else
    {
        printf("%s\n", current_directory);
        free(current_directory);
    }
}
