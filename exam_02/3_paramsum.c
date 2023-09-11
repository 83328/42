/* Assignment name  : paramsum
Expected files   : paramsum.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays the number of arguments passed to it, followed by
a newline.

If there are no arguments, just display a 0 followed by a newline.

Example:

$>./paramsum 1 2 3 5 7 24
6
$>./paramsum 6 12 24 | cat -e
3$
$>./paramsum | cat -e
0$
$> */

/* #include <unistd.h>

void	ft_putnbr(int nbr)
{
	char digit;

	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	digit = (nbr % 10) + '0';
	write(1, &digit, 1);
}

int main(int ac, char **av)
{
	if(ac < 2)
		write(1, "0", 1);
	else
		ft_putnbr(ac - 1);
	write(1, "\n", 1);
} */

#include <unistd.h>

void	ft_putnbr(int nbr)
{
	char digit;
	if(nbr >9)
		ft_putnbr(nbr / 10);
	digit = (nbr %10) + '0';
	write(1, &digit, 1);
}

int main(int ac, char **av)
{
if (ac >= 2)
	ft_putnbr(ac-1);
else
	write(1, "0", 1);
write(1, "\n", 1);
}

/* #include <unistd.h>
void ft_putnbr(int n)
{
	if(n >= 10)
	{
		ft_putnbr(n / 10);
		n = n % 10;
	
	}
	if(n < 10)
	{
		n = n + 48;
		write(1, &n, 1);
	
	}
}
int main(int ac, char **av)
{
	
	
	if(ac < 2)
		write(1, "0", 1);
	else
	{
		ft_putnbr(ac - 1);
	
	
	}
	write(1, "\n", 1);
} */