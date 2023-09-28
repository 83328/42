/* Assignment name  : fprime
Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------------------------------------------------------

Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there is one, will be valid.

Examples:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$ */

#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int nbr;
	int first = 1;
	int divider = 2;

	if(ac == 2 && (nbr = atoi(av[1])) > 0)
	{
		if (nbr == 1)
			printf("1");
		else
		{
			while(nbr != 1)
			{
				if (nbr % divider == 0)
				{
					if (first)
						first = 0;
					else
						printf("*");
					printf("%i", divider);
					nbr = nbr / divider;		
				}
				else
					++divider;
			}
		}
	}
	printf("\n");
}

#include<stdlib.h>
#include<stdio.h>

int main(int ac, char **av)
{
int nbr;
int first = 1;
int divider = 2;
int flag = 0;

if(ac == 2 && atoi(av[1]) > 0)
{
nbr = atoi(av[1]);
	if(nbr == 1)
		printf("1");
	else
	{
		while(nbr != 1)
		{
			if(nbr % divider == 0)
			{
				if(flag == 1)
				{
					printf("*");
				}
				printf("%i", divider);
				flag = 1;
				nbr = nbr / divider;
			}
			else
				divider++;
		}

	}
}
printf("\n");
}

/* 
#include <stdio.h>
#include <stdlib.h>

int		is_prime(int n)
{
	int i = 2;

	while (i < n)
	{
		if (n % i == 0)
			return (0);
		++i;
	}
	return (1);
}

void	fprime(char *str)
{
	int n = atoi(str);
	int factor = 2;
	int first = 1;

	if (n == 1)
		printf("1");

	while (factor <= n)
	{
		if (n % factor == 0 && is_prime(factor))
		{
			if (first == 1)
				printf("%d", factor);
			else
				printf("*%d", factor);
			first = 0;
			n = n / factor;
		}
		else
			++factor;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		fprime(argv[1]);

	printf("\n");
	return (0);
} */