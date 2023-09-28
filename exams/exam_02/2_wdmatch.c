/* Assignment name  : wdmatch
Expected files   : wdmatch.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.

If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.

If the number of arguments is not 2, the program displays a \n.

Examples:

$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
$
$>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
quarante deux$
$>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
$
$>./wdmatch | cat -e
$ */

#include <unistd.h>

void ft_putstr(char const *str)
{
	int i = 0;

	while (str[i])
		write(1, &str[i++], 1);
}

int	main(int argc, char const *argv[])
{
	int i = 0;
	int j = 0;

	if (argc == 3)
	{
		while (argv[2][j])
			if (argv[2][j++] == argv[1][i])
				i++;
		if (!argv[1][i])
			ft_putstr(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}

//working one after the exam
/* #include <unistd.h>

void	ft_putstr(char *str)
{
	int i = 0;

	while (str[i])
		write (1, &str[i++], 1);
}

void check(char *str1, char *str2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(str2[j])
	{
		if(str1[i] == str2[j])
		{
			i++;
		}
		j++;
	}
	if (str1[i] == '\0')
		ft_putstr(str1);
}

int main(int ac, char **av)
{
	if(ac == 3)
	{
		check(av[1], av[2]);
	}
	write(1, "\n", 1);
	return(0);
}
 */