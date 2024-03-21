#include "libft.h"

int ft_strcmp(const char *s1, const char *s2)
{
    size_t i;
    size_t n;
    int len1;
    int len2;


    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);

    if (len1 > len2)
        n = len1;
    else
        n = len2;
    i = 0;
    while(i < n)
    {
        if (s1[i] == 0 && s2[i] == 0)
            return (0);
        if(s1[i] != s2[i])
            return (1);
        i++;
    }
    return(0);
}