/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:45:04 by alimpens          #+#    #+#             */
/*   Updated: 2023/11/24 16:34:34 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int is_exit_command(const char* input)
{
	// Check if the input is the exit command (case-insensitive)
	return (strcasecmp(input, "exit\n") == 0 || strcasecmp(input, "exit\n") == 0);
}
