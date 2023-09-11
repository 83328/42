/* Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);
 */
 
 // !!! NOT PASSING THE TRIAL EXAM !!!
#include <stdio.h>
#include <string.h>
#include <stddef.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int     i = 0;
	int j;

	while (s[i] != '\0')
	{
		j = 0;
		while (reject[j] != '\0')
		{
			if(s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

int main(void)
{
	size_t      i;
	size_t      i___;
	const char  str1[5] = "x++x\0";
	const char  str2[3] = "xx\0";

	i = ft_strcspn(str1, str2);
	i___ = strcspn(str1, str2);
	printf("%d\n", i);
	printf("%d\n", i___);
}
