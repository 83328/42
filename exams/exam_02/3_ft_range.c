/* Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3. */

/* #include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	*res;
	int	size;
	int	i;

	size = (end - start) + 1;
	i = 0;
	res = (int *) malloc(size * sizeof(int));
	if (!res)
		return (NULL);
	while (i++ < size)
		res[i] = start + i;
	return (res);
} */

#include <stdlib.h>
#include <stdio.h>

int     absolute_value(int n)
{
    if (n < 0)
        return (-n);
    return (n);
}
 
int     *ft_range(int start, int end)
{
    int number_of_ints;
    int *array;
    int step;
    int i;
 
    number_of_ints = 1 + absolute_value(end - start);
    array = malloc(sizeof(int) * number_of_ints);
 
    if (start < end)
        step = 1;
    else
        step = -1;
 
    i = 0;
    while (i < number_of_ints)
    {
        array[i] = start;
        start = start + step;
        ++i;
    }
    return (array);
}

int		main(void)
{
	int		*tab;

	tab = ft_range(3, 6);
	printf("%d\n", tab[0]);
	printf("%d\n", tab[1]);
	printf("%d\n", tab[2]);
	printf("%d\n", tab[3]);
	//printf("%d\n", tab[3]);
}
