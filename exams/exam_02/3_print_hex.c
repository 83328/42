/* Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$ */

int ft_atoi(char *str)
{
	int result;
	int sign;
	int i;

	result = 0;
	sign = 1;
	i = 0;
	while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if(str[i] == '-')
		sign = -1;
	if(str[i] == '-' || str[i] == '+')
		i++;
	while(str[i] >= '0' && str[i] <= '9')
	{
		result = result*10 + str[i] - '0';
		i++;
	}
	return(sign * result);
}

void	print_hex(int n)
{
	char hex_digits[] = "0123456789abcdef";

	if (n >= 16)
		print_hex(n / 16);
	write(1, &hex_digits[n % 16], 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		print_hex(ft_atoi(av[1]));
	write(1, "\n", 1);
}


/*
#include <unistd.h>

int	ft_atoi(char *str)
{
	int n = 0;

	while (*str != '\0')
	{
		n = n * 10;
		n = n + *str - '0';
		++str;
	}
	return (n);
}

void	print_hex(int n)
{
	char hex_digits[] = "0123456789abcdef";

	if (n >= 16)
		print_hex(n / 16);
	write(1, &hex_digits[n % 16], 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		print_hex(ft_atoi(argv[1]));
	write(1, "\n", 1);
}


#include <unistd.h>

void conv_hex(int number);

int main(int ac, char **av)
{
	int number;
	char *str;
	
	number = 0;
	if(ac == 2)
	{
		str = av[1];
		
		while(*str)
		{
			number = number * 10 + (*str - '0');
			str++;
		}#include <unistd.h>

void conv_hex(int number);

int main(int ac, char **av)
{
	int number;
	char *str;
	
	number = 0;
	if(ac == 2)
		conv_hex(number);
	}
write(1, "\n", 1);
}

void conv_hex(int number)
{
	char *base;
	
	base = "0123456789abcdef";
	if (number / 16 > 0)
		conv_hex(number / 16);
	write(1, base + number % 16, 1);
	//write(1, base[number % 16], 1);
}



number = 0
123

'1' - '0' == 1

number = 1
'2'
number = 1 * 10 + 2 = 12

number = 12
'3'

number = 12 * 10 + 3 = 123
*/
