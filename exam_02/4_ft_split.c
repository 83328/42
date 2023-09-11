/* Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str); */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **ft_split(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int word_count = 0;
    int len = strlen(str);

    while (i < len)
    {
        while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
            i++;
        if (str[i])
	    {
            word_count++;
            while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
                            i++;
        }
    }
    char **result = (char**)malloc(sizeof(char*) * (word_count + 1));
    if (result == NULL)
        return NULL;
    i = 0;
    while (i < len)
    {
        while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
            i++;
        if (str[i])
	    {
            j = i;
            while (str[j] && (str[j] != ' ' && str[j] != '\t' && str[j] != '\n'))
                j++;
            result[k] = (char*)malloc(sizeof(char) * (j - i + 1));
            if (result[k] == NULL)
                return NULL;
            strncpy(result[k], str + i, j - i);
            result[k][j - i] = '\0';
            k++;
            i = j;
        }
    }
    result[k] = NULL;
    return result;
}
