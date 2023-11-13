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
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int ft_putchar(char c, int *len)
{
	*len = *len + 1;
	return(write(1, &c, 1));
}

int ft_putstr(char *str, int *len)
{
	long unsigned int i = 0;
	int res = 0;
	
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
	return(res);
}

int ft_putnbr(int n, int *len)
{
	int res = 0;
	
	if(n == -2147483648)
		res = ft_putstr("-2147483648", len);
	else
	{
		if(n < 0)
		{
			res = ft_putchar('-', len);
			n = -n;
		}
		if(n > 9)
		{
			ft_putnbr(n / 10, len);
			ft_putnbr(n % 10, len);			
		}
		if(n < 10)
		{
			res = ft_putchar((n%10)+'0', len);
		}
	}
	return(res);
}

int ft_puthex(int n, char c, int *len)
{
	unsigned int	u = (unsigned int)n;
	int		ret = 0;
	
	if (u >= 16)
	{
		ft_puthex(u / 16, c, len);
		ft_puthex(u % 16, c, len);
	}
	else
	{
		if (c == 'x')
			ret = ft_putchar("0123456789abcdef"[u % 16], len);
	}
	return (ret);
}

int conditions(const char *next, va_list *a, int *len)
{
	int res = 0;
	
	if(*next == 's')
		res = ft_putstr(va_arg(*a, char *), len);
	else if (*next == 'd')
		res = ft_putnbr(va_arg(*a, int), len);
	else
		res = ft_puthex(va_arg(*a, int), *next, len);
	return(res);
}

int	ft_printf(const char *str, ...)
{
	va_list ap; //ap = argument pointer
	int len = 0;
	int error = 0;

	va_start(ap, str);
	while(*str)
	{
		if(*str== '%')
			error = conditions(++str, &ap, &len);
		else
			error = ft_putchar(*str,  &len);
		if(error < 0)
			return(error);
		str++;
	}
	va_end(ap);
	return(len);
}

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
}