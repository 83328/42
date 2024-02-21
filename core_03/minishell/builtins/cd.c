#include "../minishell.h"

/* int cd_command(int ac, char *av[])
{
	int i = 0;
	while (av[i] != NULL)
	{
		printf("Arguments for cd: %d: %s\n", i, av[i]);
		i++;
	}

	if (ac != 2)
	{
		return 1;
	}
	if (chdir(av[1]) != 0)
	{
		perror("chdir");
		return 1;
	}

	return 0;
} */

void cd_command(int arg_count, char** args) 
{
  char cwd[PATH_MAX];

  if (arg_count < 2) 
  {
    fprintf(stderr, "cd: expected 1 argument\n");
    return;
  }
  if (arg_count > 2) 
  {
    fprintf(stderr, "cd: too many arguments\n");
    return;
  }
	char* path = args[1];
	if (chdir(path) != 0)
  {
    perror("chdir() error");
    return;
  }
  if (getcwd(cwd, sizeof(cwd)) != NULL)
  {
    printf("%s\n", cwd);
  }
  else
  {
    perror("getcwd() error"); 
  }
}
