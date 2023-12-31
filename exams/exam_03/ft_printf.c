/* 
Assignment name  : ft_printf
Expected files   : ft_printf.c
Allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end
--------------------------------------------------------------------------------

Write a function named `ft_printf` that will mimic the real printf with the following constraints:

- It will manage only the following conversions: s,d and x
- It will manage the minimum field width. (we will never test with a field width of 0)
- It will manage only the precison flag `.`.

Your function must be declared as follows:

int ft_printf(const char *, ... );

Before you start we advise you to read the `man 3 printf` and the `man va_arg`.
To test your program compare your results with the true printf.

Examples of the function output:

call: ft_printf("%10.2s\n", "toto");
out:        to$

call: ft_printf("Magic %s is %5d", "number", 42);
out:Magic number is    42%

call: ft_printf("Hexadecimal for %d is %x\n", 42, 42);
out:Hexadecimal for 42 is 2a$


*****************************************************************
***** UPDATE: This function passed the exam on Nov 16, 2023 *****
*****************************************************************

*/


#include <stdarg.h>
#include <unistd.h>

void ft_putchar(char c, int *len)
{
	*len = *len + 1;
	write(1, &c, 1);
}

void ft_putstr(char *str, int *len)
{
	long unsigned int i = 0;
	
	 if(!str)
	 	ft_putstr("(null)", len);
	 else
	 {
		while(str[i])
		{
			ft_putchar(str[i], len);
			i++;
		}
	 }
}

void ft_putnbr(int n, int *len)
{
	if(n == -2147483648)
		ft_putstr("-2147483648", len);
	else
	{
		if(n < 0)
		{
			ft_putchar('-', len);
			n = -n;
		}
		if (n > 9)
			ft_putnbr(n / 10, len);
		ft_putchar((n%10) + '0', len);
	}
}

void ft_puthex(unsigned int n, int *len)
{
	if (n > 15)
		ft_puthex(n / 16, len);
	ft_putchar("0123456789abcdef"[n % 16], len);
}

void conditions(const char *next, va_list *args, int *len)
{
	if(*next == 's')
		ft_putstr(va_arg(*args, char *), len);
	else if (*next == 'd')
		ft_putnbr(va_arg(*args, int), len);
	else
		ft_puthex(va_arg(*args, int), len);
}

int ft_printf(const char *str, ... )
{
	va_list args;
	int len = 0;
	int i = 0;

	va_start(args, str);
	
	while (str[i]) 
	{
		if (str[i] == '%')
			conditions(&str[++i], &args, &len);
		else
			ft_putchar(str[i], &len);
		i++;
	}
	va_end(args);
	return(len);
}
/*
#include <stdio.h>
int main()
{
	ft_printf("%s\n", "toto");
	printf("%s\n", "toto");
	printf("\n");
	ft_printf("Magic %s is %d\n", "number", 42);
	printf("Magic %s is %d\n", "number", 42);
	printf("\n");
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("Hexadecimal for %d is %x\n", 42, 42);
}*/
