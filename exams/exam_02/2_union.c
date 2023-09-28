/* Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$> */

/* #include <unistd.h>

int check(int c, char *str, int index)
{
	int i = 0;
	
	while(i < index)
	{
		if (str[i] == c)
			return 0;
		i++;
	}
	return  1;
}

int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	int k = 0;
	
	if (argc == 3)
	{
		while(argv[1][i] != '\0')
		{
			i++;
		}
		while(argv[2][j] != '\0')
		{
			argv[1][i] = argv[2][j];
			i++;
			j++;
		}
		i--;
		while(k <= i)
		{
			if(check(argv[1][k], argv[1], k) == 1) 
				write (1, &argv[1][k], 1); 
			k++;
		}
	}
	write (1, "\n", 1);
} */


#include <unistd.h>

int check(char *str, char c, int len)
{
    int i = 0;

    while (i < len)
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}

void    ft_union(char *s1, char *s2)
{
    int i;
    int j;

    i = 0;
    while (s1[i])
    {
        if (check(s1, s1[i], i) == 0)
            write(1, &s1[i], 1);
        i++;
    }
    j = 0;
    while (s2[j])
    {
        if (check(s2, s2[j], j) == 0 && check(s1, s2[j], i) == 0)
            write(1, &s2[j], 1);
        j++;
    }
}

int main(int ac, char **av)
{
    if (ac == 3)
        ft_union(av[1], av[2]);
    write(1, "\n", 1);
}