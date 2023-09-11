/* Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str); */

#include <stdio.h>

char    *ft_strrev(char *str)
{
    int i;
    int len;
    char    tmp;

    i = 0;
    len = 0;
    while (str[len])
        len++;
    while (i < len)
    {
        len--;
        tmp = str[i];
        str[i] = str[len];
        str[len] = tmp;
        i++;
    }
    return (str);
}

#include <stdio.h>

int main()
{
    char str[] = "abcdefg";

    printf("%s\n", ft_strrev(str));
}


/* char *ft_strrev(char *str)
{
	int i = -1;
	int length = 0;
	char temporary = str[i];

	while (str[length])
		length++;
	while (++i < --length)
	{
		str[i] = str[length];
		str[length] = temporary;
	}
	return (str);
}
 */


/* //wrong interpretation
# include <unistd.h>
# include <stdio.h>
char    *ft_strrev(char *str)
{
    int flag = 0;
    int i = 0;

    while (str[i])
        i++;
    i--; 
    while (i >= 0)
    {
        while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
            i--;
        flag = i;
        i++;
        while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
        {
            write (1, &str[i], 1);

            i++;
        }
        write (1, " ", 1);//
        i = flag;
        
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\0')//
            i--;//

    }
    return (str); 
}

int main()
{
    ft_strrev("Hello  a world man");

    write (1, "\n", 1);
    return (0);
} */