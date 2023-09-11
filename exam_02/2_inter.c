/* Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$ */

#include <unistd.h>

int ft_check(char c, char *str, int i)
{
	int j = 0;
	while (str[j] && j < i)
	{
		if (str[j] == c)
			return (0);
		j++;
	}
	return (1);
}

int main(int ac, char **av)
{
	int i = 0;
	int j = 0;

	if (ac == 3)
	{
		while (av[1][i])
		{
			if (ft_check(av[1][i], av[1], i) == 1)
			{
				j = 0;
				while (av[2][j])
				{
					if (av[1][i] == av[2][j])
					{
						write(1, &av[1][i], 1);
						break;
					}
					j++;
				}
			}
			i++;
		}
	}
	write(1, "\n", 1);
}

/*#include <unistd.h>

int check(char *argv, char c, int i);
int main(int ac, char **av)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (ac == 3)
	{
		while (av[1][i])
		{
			j = 0;
			while (av[2][j])
			{
				if (av[1][i] == av[2][j])
				{
					if ((check(av[1], av[1][i], i - 1)) == 1)
						write(1, &av[1][i], 1);
					break;
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

int check(char *argv, char c, int i)
{
	// i--;
	while (argv[i])
	{
		if (c == argv[i])
			return (0);
		i--;
	}
	return (1);
}
*/

/* #include <unistd.h>

int	iter(char *str, char c, int len)
{
	int	i = 0;

	while (str[i] && (i < len || len == -1))
		if (str[i++] == c)
			return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			if (!iter(argv[1], argv[1][i], i) && iter(argv[2], argv[1][i], -1))
				write(1, &argv[1][i], 1);
			i += 1;
		}
	}
	write(1, "\n", 1);
	return (0);
} */

/*
#include <stdio.h>
#include <unistd.h>

int check(char *str, char c, int len)
{
	int i;

	i = 0;
	while (str[i] && (i < len || len == -1))
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac == 3)
	{
		while (av[1][i])
		{
			if (check(av[1], av[1][i], i) == 0 && check(av[2], av[1][i], -1) == 1)
				write(1, &av[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
} */