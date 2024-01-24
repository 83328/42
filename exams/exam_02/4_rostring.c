/* 
Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>
 */

#include <unistd.h>

void	ft_rostring(char *str)
{
	int	i = 0;
	int start = 0;
	int	end = 0;

	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	start = i;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	end = i;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != ' ' && str[i] != '\t')
			write (1, &str[i++], 1);
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		write (1, " ", 1);
	}
	while (start < end)
	{
		write (1, &str[start++], 1);
	}
}

int	main(int ac, char **av)
{
	if (ac >= 2)
		ft_rostring(av[1]);malloc
		//passed the exam with this one, the subject was unclear about this
	write (1, "\n", 1);
}
