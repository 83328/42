/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:37:38 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/01 19:20:09 by alimpens         ###   ########.fr       */
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
		//free
		g_global_sig = 0;
	}
}

void	sigint_handler_command(int sig)
{
	if (sig == SIGINT)
	{
		//rl_on_new_line();// Move to a new line
		//rl_redisplay();
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
		//write(0, "\n", 1);
	}
}

void	*signal_handling(void)
{
	signal(SIGINT, sigint_handler_default);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	return (NULL);
}
