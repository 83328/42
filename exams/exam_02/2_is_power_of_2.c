/* Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n); */


//#include <stdio.h>

/* int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n != 1)
	{
		if (n % 2)
			return (0);
		n /= 2;
	}
	return (1);
}
 */
 
#include <stdio.h>

int		is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n > 1)
	{
		if (n % 2 == 0)
			n = n / 2;
		else
			return (0);
	}
	return (1);
}

int	main(void)
{
	int i = 0;

/*     while (i < 20)
    {    
        printf("i is %d : %d\n",i ,is_power_of_2(i));
        i++;
    } */

	printf("%d\n", is_power_of_2(-3));
}

/* int	main(void)
{
	int	n;

	n = 0;
	printf("%d --> %d\n", n, is_power_of_2(n));
	n = 1;
	printf("%d --> %d\n", n, is_power_of_2(n));
	n = 2;
	printf("%d --> %d\n", n, is_power_of_2(n));
	n = 3;
	printf("%d --> %d\n", n, is_power_of_2(n));
	n = 4;
	printf("%d --> %d\n", n, is_power_of_2(n));
	n = 6;
	printf("%d --> %d\n", n, is_power_of_2(n));
	n = 9;
	printf("%d --> %d\n", n, is_power_of_2(n));
	n = 10;
	printf("%d --> %d\n", n, is_power_of_2(n));
	n = 11;
	printf("%d --> %d\n", n, is_power_of_2(n));
	n = 16;
	printf("%d --> %d\n", n, is_power_of_2(n));
	n = 18;
	printf("%d --> %d\n", n, is_power_of_2(n));
} */