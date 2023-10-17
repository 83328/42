/* Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$> */

#include<unistd.h>

int ft_atoi(char *str)
{
int i = 0;
int sign = 1;
int res = 0;

while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	i++;
if(str[i] == '-')
	sign = -1;
if(str[i] == '-' || str[i] == '+')
	i++;
while(str[i] >= '0' && str[i] <= '9')
	{
	res = res * 10 + str[i] - '0';
	i++;
	}
return(sign * res);
}

void ft_putchar(char c)
{
write(1, &c, 1);
}

void ft_putnbr(int n)
{
if(n > 9)
	ft_putnbr(n/10);
ft_putchar(n % 10 + '0');
}

int main(int ac, char **av)
{
int i = 1;
int flag = 0;
int n;
int res;
if(ac == 2)
	{
	n = ft_atoi(av[1]);
	while(i < 10)
		{
		ft_putnbr(i);
		write(1, " x ", 3);
		ft_putnbr(n);
		write(1, " = ", 3);
		ft_putnbr(i*n);
		write(1, "\n", 1);
		i++;
		}
	}
else
	write(1, "\n", 1);
}

/* #include <unistd.h>

int	ft_atoi(char *str)
{
	int result;
	int sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (sign * result);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = (nb % 1000000000 * -1);
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = (nb * -1);
	}
	if (nb / 10 > 0)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

int	main(int argc, char *argv[])
{
	int	i;
	int	nbr;

	if (argc != 2)
		write(1, "\n", 1);
	else
	{
		i = 1;
		nbr = ft_atoi(argv[1]);
		while (i <= 9)
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(nbr);
			write(1, " = ", 3);
			ft_putnbr(i * nbr);
			write(1, "\n", 1);
			i += 1;
		}
	}
	return (0);
} */
//--------------------------------
#include<unistd.h>

int ft_atoi(char *str)
{
int i = 0;
int result = 0;
int sign = 1;

while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	i++;
if(str[i] == '-')
	sign = -1;
if(str[i] == '-' || str[i] == '+')
	i++;
while(str[i] >= '0' && str[i] <= '9')
	{
	result = result * 10 + str[i] - '0';
	i++;
	}
return(sign * result);
}

void ft_putchar(char c)
{
write(1, &c, 1);
}

void ft_putnbr(int nbr)
{
if (nbr == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nbr = (nbr % 1000000000 * -1);
	}
else if (nbr < 0)
	{
	write(1, "-", 1);
//	ft_putchar ('-');
	nbr = (nbr * -1);
	}
if(nbr/10 > 0)
	ft_putnbr(nbr/10);
ft_putchar(nbr % 10 + '0');
}

int main(int ac, char **av)
{
int i = 0;
int nbr;
if(ac != 2)
	write(1, "\n", 1);
else
	{
	i = 1;
	nbr = ft_atoi(av[1]);
	while(i <= 9)
		{
		ft_putnbr(i);
		write(1, " x ", 3);
		ft_putnbr(nbr);
		write(1, " = ", 3);
		ft_putnbr(i * nbr);
		write(1, "\n", 1);
		i = i + 1;
		}
	}
return(0);
}
