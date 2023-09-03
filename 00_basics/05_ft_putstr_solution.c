/*
Put String

Write a function that prints the given string.
Make a main function that can get argument(s).
Call the function with argument(s) in reverse order and after every call print a new line.
Your project must be written in accordance with the Norm of 42 (except for the 42 header).

Function:
	name:		ft_putstr
	arguments:	char *str
	returns:	void

Allowed external functions:
	write from <unistd.h>

Compile:
	cc -Wall -Wextra -Werror 05_ft_putstr_solution.c -o ft_putstr

Run:
	./ft_putstr <your arguments>

Tests:
	./ft_putstr "Hello, World!"
	./ft_putstr 42
	./ft_putstr 42 -123454321 AbC-1_3
	./ft_putstr A "" B "" C '' D " "
	./ft_putstr " " " "
	./ft_putstr "NULL"
	./ft_putstr "char *str"
	./ft_putstr "\n"
	...
*/

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[argc - i]);
		ft_putstr("\n");
		i++;
	}
	if (argc == 1)
		ft_putstr("\n");
}
