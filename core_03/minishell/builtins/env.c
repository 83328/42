#include "../minishell.h"

void env_command()
{
  extern char** environ;
  int i = 0;
  while (environ[i] != NULL)
  {
    printf("%s\n", environ[i]);
    i++; 
  }
}

