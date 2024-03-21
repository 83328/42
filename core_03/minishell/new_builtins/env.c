#include "../minishell.h"

void    env(char **env_cp)
{
    int i;

    i = 0;
    while (env_cp[i] != NULL)
    {
        ft_printf("\nstrArr[%d] %s", i ,env_cp[i]);
        i++;
    }
    ft_printf("\n");
}