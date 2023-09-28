/* Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str); */

/* int	ft_atoi(char *str)
{
	int result = 0;
	int sign = 1;

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
} */

int	ft_atoi(const char *str)
{
int i = 0;
int result = 0;
int sign = 1;

while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	i++;
if(str[i] == '-')
	sign = -1;
if(str[i] == '-' || str[i] == '+')
	i++;
while(str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10 + str[i] - '0');
		i++;
	}
return(sign * result);
}

/*
int	ft_atoi(const char *str)
{
    int i;
    int neg;
    int result;

    i = 0;
    neg = 1;
    result = 0;
    while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
        i++;
    if (str[i] == '-')
    {
        neg = -neg;
        i++;
    }
    else if (str[i] == '+')
        i++;
    while ('0' <= str[i] && str[i] <= '9' && str[i])
    {
        result = result * 10 + str[i] - '0';
        i++;
    }
    return (result * neg);
}

int main()
{
    printf("%d\n", ft_atoi("-112i04"));
    printf("%d\n", ft_atoi("    -42inlnq1324"));
}
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"

int ft_atoi(char *str)
{
int result = 0;
int sign = 1;
int i = 0;

while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	i++;
if(str[i] == '-')
	sign = -1;
if(str[i] == '-' || str[i] == '+')
	i++;
while(str[i] >= '0' && str[i] <= '9')
	{
	result = result*10 + (str[i] - '0');
	i++;
	}
return(sign*result);
}


int main()
{
	printf(KRED "%d\n", ft_atoi("--11204"));
	printf(KRED "%d\n", atoi("--11204"));
	printf(KGRN "%d\n", ft_atoi("    -42inlnq1324"));
	printf(KGRN "%d\n", atoi("    -42inlnq1324"));
	printf(KRED "%d\n", ft_atoi("12"));
	printf(KRED "%d\n", atoi("12"));
	printf(KGRN "%d\n", ft_atoi("lala2"));
	printf(KGRN "%d\n", atoi("lala2"));
	printf(KRED "%d\n", ft_atoi("    -4a12"));
	printf(KRED "%d\n", atoi("    -4a12"));
}