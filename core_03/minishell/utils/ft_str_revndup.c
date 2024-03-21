#include "../minishell.h"

char    *ft_str_revndup(const char *str, int n)
{
    char    *new_str;
    int     i;

    i = 0;
    new_str = malloc(sizeof(char) * (ft_strlen(str) - n));
    while (str[n] != 0)
    {
        new_str[i] = str[n];
        n++;
        i++;
    }
    new_str[i] = 0;
    return (new_str);
}