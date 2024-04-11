/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_splitting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:33:24 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/10 17:49:16 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	process_redirection(char *token, char **tokens, int *i)
{
	char	*redirection;

	redirection = strtok(token, ">");
	tokens[(*i)++] = strdup(redirection);
	tokens[(*i)++] = strdup(">");
	if (strstr(token, ">") != NULL)
		tokens[(*i)++] = strdup(">");
	redirection = strtok(NULL, ">");
	if (redirection != NULL)
		tokens[(*i)++] = strdup(redirection);
}
