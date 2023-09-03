/*
Put String

Write a function that prints the given string.
Make a main function to call/test this function.
Your project must be written in accordance with the Norm of 42 (except for the 42 header).

Function:
	name:		ft_putstr
	arguments:	char *str
	returns:	void

Allowed external functions:
	write from <unistd.h>

Compile:
	cc -Wall -Wextra -Werror 02_ft_putstr_solution.c -o ft_putstr

Run:
	./ft_putstr

Tests:
	ft_putstr("Hello, World!")
	ft_putstr("42")
	ft_putstr("")
	ft_putstr(" ")
	ft_putstr("NULL")
	ft_putstr("char *str")
	ft_putstr("\n")
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

int	main(void)
{
	ft_putstr("Hello, World!");
	ft_putstr("\n");
	ft_putstr("42");
	ft_putstr("\n");
	ft_putstr("");
	ft_putstr("\n");
	ft_putstr(" ");
	ft_putstr("\n");
	ft_putstr("NULL");
	ft_putstr("\n");
	ft_putstr("char *str");
	ft_putstr("\n");
}
