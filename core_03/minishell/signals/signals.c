/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:37:38 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/25 13:50:18 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void sigint_handler_default(int sig) 
{
	if (sig == SIGINT)
	{
		rl_replace_line("", 0);  // Clear the current input line
		printf("\n");
		printf("minishell ## ");
		//free
		global_sig = 0;
	}
}

void	sigint_handler_command(int sig)
{
	if (sig == SIGINT) //blocking command
	{
		//rl_on_new_line();// Move to a new line
		//rl_redisplay();
		printf("\n");
		global_sig = 2;
	}
}
void	sigint_handler_heredoc(int sig)
{
	if (sig == SIGINT)
	{
	global_sig = 2;
	//printf("minishell ## ");
	rl_on_new_line();
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	//write(0, "\n", 1);
	}
}

void	*signal_handling()
{
	signal(SIGINT, sigint_handler_default); //crtl-c
	signal(SIGQUIT, SIG_IGN); //crtl-backslash
	signal(SIGTSTP, SIG_IGN); //crtl-z
	return (NULL);
}
