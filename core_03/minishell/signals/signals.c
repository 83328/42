/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 06:38:15 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/12 19:07:57 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sigint_handler_default(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_global_sig = 2;
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
