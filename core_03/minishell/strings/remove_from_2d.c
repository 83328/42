#include "../minishell.h"

void    free_2d(char **array)
{
    int i;

    i = 0;
    while (array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
}

int ft_array_len(char **array)
{
    int i;

    i = 0;
    while (array[i])
        i++;
    return (i);
}

char	**remove_from_2d(char **array, int index)
{
    int		i;
    char	**new_array;

    i = 0;
    new_array = malloc(sizeof(char *) * (ft_array_len(array)));
    if (!new_array)
        return (NULL);
    
    while (i < index)
    {
        new_array[i] = ft_strdup(array[i]);
        i++;
    }
    i++;
    while (array[i])
    {
        new_array[i-1] = ft_strdup(array[i]);
        i++;
    }
    new_array[i-1] = NULL; 
    free_2d(array);

    return (new_array); // Return new array
}

/* char	**remove_from_2d(char **array, int index)
{
  int		i;
  char	**new_array;

  i = 0;
  
  printf("Removing index %d from array\n", index); 
  
  new_array = malloc(sizeof(char *) * (ft_array_len(array)));
  if (!new_array)
  {
    printf("Failed to allocate new array\n");
    return NULL; 
  }

  printf("New array allocated at %p\n", new_array);

  while (i < index)
  {
    new_array[i] = ft_strdup(array[i]);
    i++; 
  }
  printf("New array before modifying: \n");
  
  int i = 0;
  while (new_array[i])
  {
    printf("%s\n", new_array[i]); 
    i++;
  }

  // function body

  // Print new_array before return
  printf("New array returning: \n");

  i = 0;
  while (new_array[i])
  {
    printf("%s\n", new_array[i]);
    i++; 
  }

  return new_array;
} */