/* Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src); */

#include <stdlib.h>

char    *ft_strdup(char *src)
{
	int i = 0;
	char *dest;
	int len;

	while(src[i])
		i++;
	len = i;
	i = 0;
	dest = malloc(len+1);
	
	if(dest != NULL)
	{
		while(src[i])
			{
			dest[i] = src[i];
			i++;
			}
		dest[i] = '\0';
	}
	return(dest);
}

#include<stdlib.h>

char    *ft_strdup(char *src)
{
	int i = 0;
	int len;
	char *dest;

	while(src[i])
		i++;
	len = i;
	i = 0;
	dest = malloc(len + 1);
	
	while(src[i])
		{
		dest[i] = src[i];
		i++;
		}
	dest[i] = '\0';
	return(dest);
}

/* #include <stdlib.h>

char    *ft_strdup(char *src)
{
	char *dest;
	int i = 0;
	int len = 0;

	while(src[len])
		len++;
	dest = malloc(len + 1);
	if (dest != '\0')
	{
		while(src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return(dest);
}
 */
/* 
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int	i = 0;
	int	length = 0;
	char	*strcpy;

	while (src[length])
		length++;
	strcpy = malloc(sizeof(*strcpy) * (length + 1));
	if (strcpy != NULL)
	{
		while (src[i])
		{
			strcpy[i] = src[i];
			i++;
		}
		strcpy[i] = '\0';
	}
	return (strcpy);
}
 */