#include "../minishell.h"

int unset_command(char **env_cp, const char *varname)
{
    int i, j;
    int env_count = 0;

    // Count the number of environment variables
    while (env_cp[env_count] != NULL) {
        env_count++;
    }

    // Find the environment variable to unset
    for (i = 0; i < env_count; i++) {
        if (strncmp(env_cp[i], varname, ft_strlen(varname)) == 0 && env_cp[i][ft_strlen(varname)] == '=') {
            // Free memory for the variable
            free(env_cp[i]);
            // Shift subsequent elements to fill the gap
            for (j = i; j < env_count - 1; j++) {
                env_cp[j] = env_cp[j + 1];
            }
            env_cp[j] = NULL; // Set the last element to NULL
            return (0); // env var existed
        }
    }
    return (1); // env var didnt exist
}
