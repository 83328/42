/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:20:34 by alimpens          #+#    #+#             */
/*   Updated: 2024/01/16 12:24:22 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int cd_command(int argc, char *argv[])
{
	if (argc != 2)
	{
		return 1;
	}
	if (chdir(argv[1]) != 0)
	{
		perror("chdir");
		return 1;
	}
	printf("Changed directory to: %s\n", argv[1]);
	return 0;
}
