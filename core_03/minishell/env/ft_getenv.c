#include "../minishell.h"

char    *ft_getenv(const char* varname, char **env_copy)
{
    char* current;
    int i = 0;
    while (env_copy[i] != NULL) 
    {
        current = env_copy[i];
        if (ft_strncmp(varname, current, strlen(varname)) == 0 && current[strlen(varname)] == '=') {
            return &current[strlen(varname) + 1]; // Return the value after the equal sign
        }
        i++;
    }
    printStringArray(env_copy);
    return NULL; // Variable not found
}
