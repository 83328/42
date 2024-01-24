/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:44:36 by alimpens          #+#    #+#             */
/*   Updated: 2024/01/17 14:44:53 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void sigint_handler(int sig) 
{
	if (sig == SIGINT && global_sig == 0)
	{
		// rl_on_new_line();
		// rl_replace_line("", 0);  // Clear the current input line
		// //printf("minishell $ ");
		//rl_redisplay();
		printf("\n");
		printf("minishell $ ");
		//printf("test2");
	}
	else if (sig == SIGINT && global_sig == 1)
	{
		//rl_on_new_line();// Move to a new line
		//rl_redisplay();
		printf("\n");
	}
	//printf("minishell $ ");  // Redisplay the prompt
	//input = readline("minishell >> ");
}