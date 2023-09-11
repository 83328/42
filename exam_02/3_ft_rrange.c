/* Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0. */

/* #include <stdio.h>
#include <stdlib.h>

int n;

int *rrange(int start, int end)
{
    int *range;
    int i;

    if(start>end)
        return rrange(end,start); //so that start is always <end

    n=end-start+1; // n globally declared 

    range=malloc(n*sizeof(int)); //casting is not required
    if(range==NULL)
        printf("fail");

    for(i=0;i<n;i++,start++)
    {
        range[i]=start;
    }

    return range;
} */

/* int main() 
{
	int numb_range;
    int i;
    int start;
    int end;
    int *numbers;

    i = 0;
    start = 2147483647;
    end = 2147483640;
    if (end > start)
        numb_range = end - start + 1;
    else
        numb_range = start - end;
    // numbers = (int *)malloc(sizeof(int) * numb_range);
    numbers = rrange(start, end);
    while (i <= numb_range)
        printf("%d |", numbers[i++]);
	return 0;
} */

#include <stdlib.h>

int *ft_rrange(int start, int end)
{
	int *range;
	int i = 0;
	int n = end - start + 1;

	if (start > end)
		return (ft_rrange(end, start));
	range = (int *)malloc(sizeof(int) * n);
	if (range)
	{
		while (i < n)
		{
			range[i] = start;
			start++;
			i++;
		}
	}
	return (range);
}
