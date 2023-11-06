/* Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsig
ned int len);
The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.
*/

int max(int *tab, unsigned int len)
{
	int result;
	int i = 0;
	result = tab[i];
	
	while(i < len)
	{
		if (result <  tab[i])
			result = tab[i];
		i++;
	}
	return result;
}
/* 
#include<string.h>

int		max(int* tab, unsigned int len)
{
	int i = 0;
	int max = tab[i];
	if(len == 0)
		return(0);
	while(i <= len)
	{
		if(tab[i] >= max)
			max = tab[i];
		i++;
	}
	return(max);
} */