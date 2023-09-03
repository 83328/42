/*
Put String

Write a function that prints the given string as first argument but prints the second argument instead of every digits.
Make a main function that can get argument(s).
Call the function with argument(s) and after every call print a new line.
Your project must be written in accordance with the Norm of 42 (except for the 42 header).

Function:
	name:		ft_putstr
	arguments:	char *str
				char c
	returns:	void

Allowed external functions:
	write from <unistd.h>

Compile:
	cc -Wall -Wextra -Werror 08_ft_putstr_solution.c -o ft_putstr

Run:
	./ft_putstr <your arguments>

Tests:
	./ft_putstr "Hello, World!" X
	./ft_putstr 42 X
	./ft_putstr -123454321 X
	...
*/

#include <unistd.h>

void	ft_putstr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ('0' <= str[i] && str[i] <= '9')
			write (1, &c, 1);
		else
			write (1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_putstr(argv[1], argv[2][0]);
	ft_putstr("\n", 'X');
}
