#include "../minishell.h"

int *find_real_pipes(char *input)
{
	int flag;
	int i;
	int *real_pipe_indices;
	int nth_pipe;
	int num_pipes;


	i = 0;
	num_pipes = 0;
	if (input[0] == '|')
		perror_exit("Error: pipe at beginning of command");
	while (input[i])
	{
		if (input[i] == '|')
			num_pipes++;
		i++;
	}
	real_pipe_indices = ft_calloc(num_pipes, sizeof(int));
	i = 0;
	nth_pipe = 0;
	while (input[i])
	{
		if (input[i] == '\"' || input[i] == '\'')
		{
			flag = input[i];
			i++;
			while (input[i] != flag)
				i++;
		}
		if (input[i] == '|')
		{
			real_pipe_indices[nth_pipe] = i;
			nth_pipe++;
		}
		i++;
	}
	if(input[i-1] == '|')
		perror_exit("ends on pipe"); 
	real_pipe_indices[nth_pipe] = -1;
	return (real_pipe_indices);
}

char    **pipe_split(char *input) //splits a string by pipes that are not inbetween 2 quotes of same kind
{
	char    **split_by_pipes;
	int     *real_pipe_indices; //array of indexes of real pipes
	int     i;

	i = 0;
	real_pipe_indices = find_real_pipes(input);
	split_by_pipes = split_by_index(input, real_pipe_indices);
	return (split_by_pipes);
}