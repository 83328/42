#include "../minishell.h"

int count_til_squote(char *line, int i);
char	*copy_til_squote(char *line, int i) //copies the string using its own i-var til it reaches a double quote,returns malloced str+0 (perror-exit if unclosed)
{
	int     n;
    char    *ret;
	int		j;

	j = 0;

	n = count_til_squote(line, i);
	// printf("\npassed count_til_squote");
	// printf("\nresult of count_til_squote: %i", n);
	// ret = calloc(n + 1,sizeof(char));
	ret = ft_calloc(sizeof(char),n + 1);
	while(line[i] != 39 && line[i] != 0)
	{
		if (line[i] == 0)
			perror_exit("error: unclosed single quotes"); //already happens in count til quote but f it.
		ret[j] = line[i];
		i++;
		j++;
	}
	if (ret[j - 1] == 0)
	{
		perror_exit("error: unclosed single quotes");
	}
	ret[j] = '\0';
	return(ret);
}

int count_til_squote(char *line, int i)
{
	int n;

    n = 0;
	while(line[i] != 39 && line[i] != 0)
	{
		// if (line[i] == 0)
		// 	perror_exit("1error: unclosed single quotes");
		i++;
		n++;
	}
	if (line[i - 1] == 0)
		perror_exit("1error: unclosed single quotes");
	return(n);
}