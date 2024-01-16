/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:13:30 by alimpens          #+#    #+#             */
/*   Updated: 2024/01/16 14:09:00 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char* pwd(void)
{
  char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
      return ft_strdup(cwd);
    else
    {
      perror("pwd");
      return NULL; 
    }
}
