/* Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
	 ||
	 \/
 0110  0100 */

/* #include <stdio.h>
#include <unistd.h>

unsigned char	reverse_bits_2(unsigned char octet)
{
    unsigned char   ret = 0;
    int i = 8;

    while (i--)
    {
        ret = (ret << 1) + (octet & 1);
        octet = octet >> 1;
    }
    return (ret);
}


void	print_bits(unsigned char octet)
{
	unsigned char   bit;
	int i = 8;

	while (i > 0)
	{
		i--;
		bit = (octet >> i & 1) + '0';
		write (1, &bit, 1);
	}
}
unsigned char reverse_bits(unsigned char octet)
{
	int i = 8;
	unsigned char res = 0;

	while (i > 0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (res);
}

int	main(void)
{
	unsigned char c;

	c = '1';
	print_bits(5);
	printf("\n");
	print_bits(reverse_bits(5));
	printf("\n");
	print_bits(reverse_bits_2(5));
}  */


#include<unistd.h>

void	print_bits(unsigned char octet)
{
	int i = 8;
	unsigned char bit;

	write(1, "Prn :", 5);
	while(i>0)
	{
		bit = ((octet >> i &1)+'0');
	//	write(1, &bit, 1);
		return(bit);
		i--;
	}
}

void	reverse_bits(unsigned char octet)
{
	int i = 0;
	unsigned char res;

	write(1, "Rev :", 5);
	while(i<8)
	{
		res = ((octet >> i&1)+'0');
	//	write(1, &res, 1);
		return(res);
		i++;
	}
}

int main(void)
{
	unsigned char c = 4;
	
	print_bits(c);
	write(1, "\n", 1);
	reverse_bits(c);
	write(1, "\n", 1);
}
