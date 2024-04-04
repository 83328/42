/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:37:38 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/03 13:52:07 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sigint_handler_default(int sig)
{
	if (sig == SIGINT)
	{
		rl_replace_line("", 0);
		printf("\n");
		printf("minishell ## ");
		g_global_sig = 0;
	}
}

void	sigint_handler_command(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		g_global_sig = 2;
	}
}

void	sigint_handler_heredoc(int sig)
{
	if (sig == SIGINT)
	{
		g_global_sig = 2;
		rl_on_new_line();
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
	}
}

void	*signal_handling(void)
{
	signal(SIGINT, sigint_handler_default);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	return (NULL);
}
