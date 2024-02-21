#include "../minishell.h"

void pwd_command()
{
  char cwd[PATH_MAX];

  if (getcwd(cwd, sizeof(cwd)) != NULL)
  {  
    printf("%s\n", cwd);
  }
  else
  {
    perror("getcwd() error");
    return;
  }
}
