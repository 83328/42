/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:38:27 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/03 11:25:11 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sigint_handler(int sig)
{
	if (sig == SIGINT && g_global_sig == 0)
	{
		rl_replace_line("", 0);
		printf("\n");
		printf("minishell >> ");
	}
	else if (sig == SIGINT && g_global_sig == 1)
	{
		printf("\n");
	}
}

void	*signal_handling(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	return (NULL);
}
