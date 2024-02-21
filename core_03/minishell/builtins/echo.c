#include "../minishell.h"

int echo_command(int ac, char *av[])
{
    int no_newline = 0;
    int i;
    i = 1;

    if (ac > 1 && strcmp(av[1], "-n") == 0)
    {
        no_newline = 1;
        i++;
    }
    while (i < ac)
    {
        printf("%s", av[i]);
        if (i < ac - 1)
            printf(" ");
        i++;
    }
    if (!no_newline)
        printf("\n");
    return 0;
}
