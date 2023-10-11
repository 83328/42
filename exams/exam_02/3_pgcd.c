/* Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e
1$
$> ./pgcd | cat -e
$ */


#include<stdio.h>
#include<stdlib.h>

int main(int ac, char **av)
{
int i;
int j;
int temp;
int k;

if(ac == 3)
	{
	i = atoi(av[1]);
	j = atoi(av[2]);
	
	if(i >= j)
		{
		temp = i;
		i = j;
		j = temp;
		}
	k = i;
	while(j%k != 0)
	{
		k--;
		while(i%k != 0)
			k--;
	}
	
	printf("%i\n", k);
	}
else
	printf("\n");
}

/* #include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int string1 = atoi(argv[1]);
	int string2 = atoi(argv[2]);

	if (argc != 3)
	{
		printf("\n");
		return 0;
	}
	if (string1 <=0 || string2 <= 0)
	{
		printf("\n");
		return 0;
	}
	while (number2 != 0)
	{
		//ft_swap
		int temporary = string2;
		string2 = string1 % string2;
		string1 = temporary;
	}
	printf("%d\n", string1);
	return 0;
} */