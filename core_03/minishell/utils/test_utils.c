/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgacic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:31:33 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/08 21:31:33 by dgacic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_string_array(char **str_array)
{
	int	i;

	i = 0;
	while (str_array[i] != NULL)
	{
		printf("\nstrArr[%d] #%s#", i, str_array[i]);
		i++;
	}
	printf("\n");
}

void	print_int_array(int *int_array)
{
	int	i;

	i = 0;
	while (int_array[i] != -1)
	{
		printf("\nintArr[%d] %i", i, int_array[i]);
		i++;
	}
	printf("\n");
}

void	print_file_content(int fd)
{
	char	buffer[4096];
	ssize_t	bytesread;
	ssize_t	writeresult;

	while (1)
	{
		bytesread = read(fd, buffer, sizeof(buffer));
		if (bytesread == -1)
		{
			perror("Error reading file");
			break ;
		}
		if (bytesread == 0)
		{
			break ;
		}
		writeresult = write(STDOUT_FILENO, buffer, bytesread);
		if (writeresult == -1)
		{
			perror("Error writing to stdout");
			break ;
		}
	}
	close(fd);
}
