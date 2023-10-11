/* 
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/

//#include <stdio.h>

int value_of(char c, int base)
{
char digit[17] = "0123456789abcdef";
char digit2[17] = "0123456789ABCDEF";

while(base--)
	{
	if(digit[base] == c || digit2[base] == c)
		return(1);
	}
return(0);
}

int ft_check(char c)
{
if(c >= '0' && c <= '9')
	return(c-'0');
else if (c > 'a' && c <= 'f')
	return(c - 'a' + 10);
else if (c > 'A' && c <= 'F')
	return(c - 'A' + 10);
return(0);
}

int	ft_atoi_base(const char *str, int str_base)
{
int i = 0;
int res = 0;
int sign = 1;

while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	i++;
if(str[i] == '-')
	sign = -1;
if(str[i] == '-' || str[i] == '+')
	i++;
while(value_of(str[i], str_base))
	{
	res = res * str_base + ft_check(str[i]);
	i++;
	}
return(sign * res);
}

/* 
int		main(void)
{
	printf("%d\n", ft_atoi_base("ff", 16));
    //printf("%d\n", ft_atoi_base("FF", 10));
	return 0;
}
*/

/* 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ft_no(char c)
{
    if (c <= 32)
        return (1);
    return (0);
}

int	ft_check(char c)
{
	if ('0' <= c && c <= '9')
		return (c - '0');
	else if ('a' <= c && c <= 'f')
		return (c - 'a' + 10);
	else if ('A' <= c && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int	value_of(char c, int base)
{
	char digit[17] = "0123456789abcdef";
	char digit2[17] = "0123456789ABCDEF";

	while (base--)
	{
		if (digit[base] == c || digit2[base] == c)
			return (1);
	}
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int neg = 1;
	int i = 0;
	int ret = 0;

    while (ft_no(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		i++;
		neg = -neg;
	}
	while (value_of(str[i], str_base))
	{
		ret = (ret * str_base) + ft_check(str[i]);
		i++;
	}
	return (ret * neg);
}

int		main(void)
{
	printf("%d\n", ft_atoi_base("ff", 16));
    //printf("%d\n", ft_atoi_base("FF", 10));
	return 0;
} 
*/

/* --- Attila ---

#include <stdio.h>

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_strchar_base(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_get_base(char c)
{
	if (c == 'l')
		return ("0123456789abcdef");
	else if (c == 'u')
		return ("0123456789ABCDEF");
	else
		return (NULL);
}

int	ft_get_value(char c)
{
	char	*base_l;
	char	*base_u;
	int		n;

	base_l = ft_get_base('l');
	base_u = ft_get_base('u');
	n = ft_strchar_base(base_l, c);
	if (n == -1)
		n = ft_strchar_base(base_u, c);
	return (n);
}

int	ft_atoi_base(const char *str, int base)
{
	int	i;
	int	sign;
	int	n;
	int	n_new;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	n = 0;
	while (str[i])
	{
		n_new = ft_get_value(str[i]);
		if (n_new == -1)
			return (sign * n);
		n = n * base + n_new;
		i++;
	}
	return (sign * n);
}

int	main(int argc, char **argv)
{
	int	base;

	if (argc == 3)
	{
		base = ft_atoi_base(argv[2], 10);
		printf("%d\n", ft_atoi_base(argv[1], base));
	}
} 
*/