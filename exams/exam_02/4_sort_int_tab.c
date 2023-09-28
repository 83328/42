/* Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions:
--------------------------------------------------------------------------------
Write the following function:
void sort_int_tab(int *tab, unsigned int size);
It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.
Doubles must be preserved.
Input is always coherent. */

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i = 0;
	int	swap;

	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1]) 
		{
			swap = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = swap;
			i = 0;
		}
		else
			i++;
	}
}

/* 
#include <stdio.h>

int	main()
{
	int	tab[] = {1, 15, 12, 13, 4};

	sort_int_tab(tab, 5);
	printf("%d\n", tab[0]);
	printf("%d\n", tab[1]);
	printf("%d\n", tab[2]);
	printf("%d\n", tab[3]);
	printf("%d\n", tab[4]);
	//printf("%d\n", tab[5]);
} */