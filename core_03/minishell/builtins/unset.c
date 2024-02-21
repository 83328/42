#include "../minishell.h"

int unset_command(char *variable)
{
    int *myVariable = (int *)malloc(sizeof(int));
    printf("%s\n", variable);
    if (myVariable == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    *myVariable = 42;
    printf("Before unset: %d\n", *myVariable);
    free(myVariable);
    return 0;
}
