/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:38:27 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/01 19:20:09 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sigint_handler(int sig)
{
	if (sig == SIGINT && g_global_sig == 0)
	{
		rl_replace_line("", 0);// Clear the current input line
		printf("\n");
		printf("minishell >> ");
	}
	else if (sig == SIGINT && g_global_sig == 1)
	{
		//rl_on_new_line();// Move to a new line
		//rl_redisplay();
		printf("\n");
	}
}

void	*signal_handling(void)
{
	signal(SIGINT, sigint_handler); //crtl-c
	signal(SIGQUIT, SIG_IGN); //crtl-backslash
	signal(SIGTSTP, SIG_IGN); //crtl-z
	return (NULL);
}
