/* Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$> */

#include<unistd.h>

int ft_atoi(char *str)
{
	int i = 0;
	int res = 0;
	int sign = 1;

	while(str[i] == ' ' || (str[i]>= 9 && str[i] <= 13))
		i++;
	if(str[i] == '-')
		sign = -1;
	if(str[i] == '+' || str[i] == '-')
		i++;
	while(str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return(sign * res);
}

void	ft_putnbr(int n)
{
	char digit[]= "0123456789";

	if(n>9)
		ft_putnbr(n/10);
	write(1, &digit[n%10], 1);
}

int check_prime(int nbr)
{
	int i = 3;

	if(nbr <= 1)
		return(0);
	else if(nbr % 2 == 0 && nbr > 2)
		return(0);
	while(i < (nbr / 2))
	{
		if(nbr % i == 0)
			return(0);
		i = i+2;
	}
	return(1);
}

int main(int ac, char **av)
{
	int div = 0;
	int nbr;
	int sum = 0;

	if(ac == 2)
	{
		nbr=ft_atoi(av[1]);
		div = nbr;
		while(div >1)
		{
			if(check_prime(div)==1)
				sum = sum+div;
			div--;
		}
		ft_putnbr(sum);
		write(1, "\n", 1);
	}
	else
		write(1, "0\n", 2);
}

/*#include <unistd.h>
int is_prime(int num)
{
	int i = 3;
	
	if (num <= 1)
		return (0);
	if (num % 2 == 0 && num > 2)
		return (0);
	while (i < (num / 2))
	{
		if (num % i == 0)
			return 0;
		i += 2;
	}
	return 1;
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 9)
	{
		ft_putchar(nb + '0') ;
	}
}

int	ft_atoi(char *str)
{
	int	i = 0;
	int	ret = 0;
	
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		ret = ret * 10 + str[i] - '0';
		i++;
	}
	return (ret);
}

int main(int ac, char *av[])
{
	int sum = 0;
	int nb = ft_atoi(av[1]);
	
	if (ac == 2)
	{
		while (nb > 0)
			if (is_prime(nb--))
				sum += (nb + 1);
		ft_putnbr(sum);
	}
	if (ac != 2)
		ft_putnbr(0);
	write(1, "\n", 1);
	return (0);
}
*/

#include<unistd.h>

int ft_atoi(char *str)
{
int i = 0;
int sign = 1;
int res = 0;

while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	i++;
if(str[i] == '-')
	sign  = -1;
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

void ft_putnbr(int nbr)
{
if(nbr > 9)
	{
	ft_putnbr(nbr/10);
	nbr = nbr % 10;
	}
ft_putchar(nbr + '0');
}

int is_prime(int nbr)
{
int i = 3;

if(nbr <= 1)
	return(0);
else if(nbr % 2 == 0 && nbr > 2)
	return(0);
while(i < (nbr / 2))
	{
	if(nbr % i == 0)
		return(0);
	i = i+2;
	}
return(1);
}

int main(int ac, char **av)
{
	int sum = 0;
	int nbr;
	if(ac == 2)
	{
		nbr = ft_atoi(av[1]);
		while(nbr > 1)
		{
			if(is_prime(nbr))
				sum += (nbr);
			nbr--;
		}
		ft_putnbr(sum);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
}
/*
#include<unistd.h>

int is_prime(int num)
{
	int i = 3;

	if (num <= 1)
		return (0);
	if (num % 2 == 0 && num > 2)
		return (0);
	while (i < (num / 2))
	{
		if (num % i == 0)
			return 0;
		i += 2;
	}
	return 1;
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 9)
	{
		ft_putchar(nb + '0') ;
	}
}

int ft_atoi(char *str)
{
int i = 0;
int res = 0;
int sign = 1;

while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	i++;
if(str[i] == '-')
	sign = -1;
if (str[i] == '-' || str[i] == '+')
	i++;
while(str[i] >= '0' && str[i] <= '9')
	{
	res = res*10+str[i] - '0';
	i++;
	}
return(sign * res);
}

int main(int ac, char *av[])
{
	int sum = 0;
	int nb;
	
	if (ac == 2)
	{
		nb = ft_atoi(av[1]);
		while (nb > 0)
			if (is_prime(nb--))
				sum += (nb + 1);
		ft_putnbr(sum);
	}
	else if (ac != 2)
		ft_putnbr(0);
	write(1, "\n", 1);
	return (0);
}

*/
/* 
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 9)
	{
		ft_putchar(nb + '0') ;
	}
}

int	ft_atoi(char *str)
{
	int	i = 0;
	int	ret = 0;
	
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		ret = ret * 10 + str[i] - '0';
		i++;
	}
	return (ret);
}

int	is_prime(int num)
{
	int	i = 2;

	while (i < num)
	{
		if (num % i == 0)
			return (1);
		i++;
	}
	return (0);
}

int	add_prime_sum(int n)
{
	int sum = 0;
	int	i = 2;

	while (n >= i)
	{
		if (is_prime(i) == 0)
			sum = sum + i;
		i++;
	}
	return (sum);
}

int main(int ac, char **av)
{
	int	n;

	if (ac == 2 && (n = ft_atoi(av[1])))
		ft_putnbr(add_prime_sum(n));
	else
		ft_putnbr(0);
	write (1, "\n", 1);
	return (0);
}

/* int main()
{
	int	i = 0;
	while (i < 10)
	{
		printf("i is %d : %d\n", i , is_prime(i));
		i++;
	}
} */