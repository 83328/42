/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_til_dquote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:38:37 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/24 19:38:38 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int count_til_dquote(char *line, int i);
char	*copy_til_dquote(char *line, int i) //copies the string using its own i-var til it reaches a double quote,returns malloced str+0 (perror-exit if unclosed)
{
	int     n;
    char    *ret;
	int		j;

	j = 0;
	n = count_til_dquote(line, i);
	// printf("\npassed count_til_squote");
	// printf("\nresult of count_til_squote: %i", n);
	// ret = calloc(n + 1,sizeof(char));
	ret = ft_calloc(sizeof(char),n + 1);
	while(line[i] != 34 && line[i] != 0)
	{
		if (line[i] == 0)
			error_exit("error: unclosed single quotes\n"); //already happens in count til quote but f it.
		ret[j] = line[i];
		i++;
		j++;
	}
	if (ret[j - 1] == 0)
	{
		// error_exit("error: unclosed double quotes2\n");
		write(1,"error: unclosed double quotes\n",30);
		return (NULL);
	}
	ret[j] = '\0';
	return(ret);
}

int count_til_dquote(char *line, int i)
{
	int n;

    n = 0;
	while(line[i] != 34 && line[i] != 0)
	{
		// if (line[i] == 0)
		// 	perror_exit("1error: unclosed single quotes");
		i++;
		n++;
	}
	if (line[i - 1] == 0)
	{
		// perror_exit("1error: unclosed double quotes");
		write(1,"error: unclosed double quotes\n",30);
		return (127);
	}
	return(n);
}

// #include "../minishell.h"

// int count_til_dquote(char *line, int i);
// char	*copy_til_dquote(char *line, int i) //copies the string using its own i-var til it reaches a double quote,returns malloced str+0 (perror-exit if unclosed)
// {
// 	int     n;
//     char    *ret;
// 	//printf("%s",line);
// 	n = count_til_dquote(line, i);
// 	ret = malloc(sizeof(char) * n + 1);
// 	while(line[i] != 34)
// 	{
// 		if (line[i] == 0)
// 			perror_exit("error: unclosed double quotes"); //already happens in count til quote but f it.
// 		ret[i] = line[i];
// 		i++;
// 	}
// 	ret[i] = 0;
// 	return(ret);
// }

// int count_til_dquote(char *line, int i)
// {
// 	int n;

//     n = 0;
// 	while(line[i] != 34)
// 	{
// 		if (line[i] == 0)
// 			perror_exit("1error: unclosed double quotes");
// 		i++;
// 		n++;
// 	}
// 	return(n);
// }