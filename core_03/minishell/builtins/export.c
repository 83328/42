#include "../minishell.h"

void export_command(char **args)
{
  int i;
  i = 1;

  while (args[i])
  {
    char *equal_sign = ft_strchr(args[i], '=');
    if (equal_sign)
    {
      *equal_sign = '\0';
      char *name = args[i];
      char *value = equal_sign + 1;
      char *old_value = getenv(name);
      if (old_value)
      {
        if (setenv(name, value, 1) != 0)
        {
          perror("export");
        }
      }
      else
      {
        if (setenv(name, value, 1) != 0)
        {
          perror("export");
        }  
      }
    }
    else
    {
      char *name = args[i];
      char *value = getenv(name);
      if (value)
      {
        if (setenv(name, value, 1) != 0)
        {
          perror("export");
        }
      }
      else
      {
        fprintf(stderr, "Invalid export format. Use 'name=value'.\n");
      }
    }
    i++;
  }
}

