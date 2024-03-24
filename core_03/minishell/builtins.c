/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:37:31 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/24 19:37:32 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtins(int len, char **reassembled_commands, char **envp, t_struct *stru)
{
    int     i;
    char    comm_no_args;

    i = 0;
    while (reassembled_commands[i])
    {
        comm_no_args = get_comm(reassembled_commands[i]) //gets the first word (everything until first space)
        if (strncmp("",comm_no_args) ==)
        {}
        else if(strncmp("",comm_no_args) ==)
        {}
        else if(strncmp("",comm_no_args) ==)
        {}
        i++;
    }
}
