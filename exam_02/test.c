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
