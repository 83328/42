#include <unistd.h>

void print_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char 	bit;

	while (i--)
	{
		bit = ((octet >> i) & 1) + '0';
		write(1, &bit, 1);
	}
}

void	print_hex(int n)
{
	if (n >= 16)
		print_hex(n / 16);
	write(1, &"0123456789abcdef"[n % 16], 1);
}



void	ft_write_number(int n)
{
	if (n > 9)
		ft_write_number(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

ft_atoi(char *str)
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
	res = ((res * 10) + str[i] - '0');
	i++;
	}
return(sign * res);
{
