#include "../minishell.h"

int is_builtin(char *cmd)
{
  if (strcmp(cmd, "echo") == 0)
    return 1;
  else if (strcmp(cmd, "cd") == 0)
    return 1; 
  else if (strcmp(cmd, "pwd") == 0)
    return 1;
  else if (strcmp(cmd, "export") == 0)
    return 1;
  else if (strcmp(cmd, "unset") == 0)
    return 1;
  else if (strcmp(cmd, "env") == 0)
    return 1;
  return 0; 
}
