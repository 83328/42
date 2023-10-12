/* 
Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------
Write a program that takes a string as a parameter, and prints its words in
reverse order.
A "word" is a part of the string bounded by spaces and/or tabs, or the
begin/end of the string.
If the number of parameters is different from 1, the program will display
'\n'.
In the parameters that are going to be tested, there won't be any "additional"
spaces (meaning that there won't be additionnal spaces at the beginning or at
the end of the string, and words will always be separated by exactly one space).
Examples:
$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$> 
*/

#include <unistd.h>
#include <stdio.h>

void	ft_rev_wstr(char *str)
{
	int	i = 0;
	int	start = 0;
	int end = 0;
	int	flag;

	while (str[i])
		i++;
	while (i >= 0)
	{
		i--;
		end = i;
		while (str[i] != ' ' && str[i] != '\t' && str[i])
			i--;
		start = i + 1;
		flag = start;
		while (start <= end)
			write (1, &str[start++], 1);
		if (flag != 0)
			write (1, " ", 1);
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_rev_wstr(av[1]);
	}
	write (1, "\n", 1);
}
/*
int main(int ac, char **av)
{
int i = 0;
int start = 0;
int flag;

if(ac == 2)
{
	while(av[1][i]==' ' || av[1][i] == '\t')
		i++;
	start = i;

	while(av[1][i])
		i++;
	i--;
	while(i > start)
	{
		while(av[1][i]!=' ' && av[1][i] != '\t' && av[1][i] != '\0')
			i--;
		i++;
		flag = i;
		while(av[1][i]!=' ' && av[1][i] != '\t' && av[1][i] != '\0')
			{
			write(1, &av[1][i], 1);
			i++;
			}
		i = flag;
		i--;
		i--;
		if(flag >= start+1)
			write(1, " ", 1);
	}
}
write(1, "\n", 1);
}
*/