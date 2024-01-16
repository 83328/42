#include "minishell.h"

char	*dollars_expansion(char *string)
{
	//char	*string_expanded; // return value
	char	*p_var; // potential environment variable after a $-sign.
	char	*p_val;	// value of the env variable if it exists, else NULL.
	int		i;
	int		still_dollars; // set to 0 after loop start, 1 if a dollar sign is found. run loop til no dollars left.

	i = 0;
	still_dollars = 1;
	while (still_dollars == 1)
	{
		still_dollars = 0;
		i = 0;
		while (string[i] != 0)
		{
			if (string[i] == '$')
			{
				still_dollars = 1;
				p_var = get_p_var(string, i + 1); //test dollar sign end of string!
				//printf("\ntest1");
				//printf("\n%s",p_var);
				p_val = getenv(p_var);
				//printf("\ntest2");
				if (p_val != NULL)
				{
					string = expand_var(string, p_val, i, ft_strlen(p_var)); // free the string it receives and give out a new string with only the first $-expand made 
					break;
				}
				else
				{
					string = expand_var(string, p_val, i, ft_strlen(p_var)); // free the string it receives and give out a new string with only the first $-expand made 
					break;
				}
			}
			else
				i++;
		}
	}
	//string_expanded = ft_strdup(string);
	//free(string);
	return (string);
}

// frees the string it receives and give out a new malloc'd string with the first $-expand made and everything else just copied identically
char	*expand_var(char *str, char *value, int start, int var_len)
{
	int	i;
	int j;
	int	val_len;
	char *cop_str;

	val_len = ft_strlen(value);
	//printf("%i", len);
	i = 0;
	j = 0;
	cop_str = ft_strdup(str);
	free(str);
    str = malloc(sizeof(char) * (ft_strlen(cop_str) + val_len + 1));
	while (i < start)
	{
		str[i] = cop_str[i];
		i++;
	}
	while (i < val_len + start)
	{
		str[i] = value[j];
		i++;
		j++;
	}
	j = 0;
	while (j < (int)((ft_strlen(cop_str) - var_len - 1 - start)) )
	{
		str[i] = cop_str[j + start + var_len + 1];
		i++;
		j++;
	}
	str[i] = 0;
	//printf("\n%s\n", cop_str);
	//printf("\n%s\n", value);
	printf("\n%s\n", str);
	//printf("\n%i\n", start);


	return (str);
}

char	*get_p_var(char *string, int start)
{
	char	*p_var;
	int		var_len;
	int		i;
	int		j;

	i = start;
	var_len = 0;
	while(string[i] != 0 && ft_isalnum(string[i]))
	{
		var_len++;
		i++;
	}
	p_var = malloc(sizeof(char *) * (var_len + 1));
	i = start;
	j = 0;
	while(string[i] != 0 && ft_isalnum(string[i]))
	{
		p_var[j] = string[i];
		i++;
		j++;
	}
	p_var[j] = 0;

	return(p_var);
}


// #include "minishell.h"

// char	*expand_var(char *string, char *value, int start);
// char	*get_p_var(char *string, int start);

// // char    *line_expansion(char *string)
// // {
// // 	char    *output_line;
// // 	int i;

// // 	i = 0;
// // 	if (string[i] == 39 && string[i] == 34 ) //single or double quotes
// // 	{

// // 	}
// // }

// char	*dollars_expansion(char *string)
// {
// 	//char	*string_vars_expanded; // return value
// 	char	*p_var; // potential environment variable after a $-sign.
// 	char	*p_val;	// value of the env variable if it exists, else NULL.
// 	int		i;
// 	int		still_dollars; // set to 0 after loop start, 1 if a dollar sign is found. run loop til no dollars left.

// 	i = 0;
// 	still_dollars = 1;
// 	while (still_dollars == 1)
// 	{
// 		still_dollars = 0;
// 		i = 0;
// 		while (string[i] != 0)
// 		{
// 			if (string[i] == '$')
// 			{
// 				still_dollars = 1;
// 				p_var = get_p_var(string, i + 1); //test dollar sign end of string!
// 				p_val = getenv(p_var); 
// 				if (p_val != NULL)
// 				{
// 					string = expand_var(string, p_val, i); // free the string it receives and give out a new string with only the first $-expand made 
// 					break;
// 				}
// 			}
// 			i++;
// 		}
// 	}
// 	return (string);
// }

// char	*get_p_var(char *string, int start)
// {
// 	char	*p_var;
// 	int		var_len;
// 	int		i;
// 	int		j;

// 	i = start;
// 	var_len = 0;
// 	while(string[i] != 0 && ft_isalnum(string[i]))
// 	{
// 		var_len++;
// 		i++;
// 	}
// 	p_var = malloc(sizeof(char *) * (var_len + 1));
// 	i = start;
// 	j = 0;
// 	while(string[i] != 0 && ft_isalnum(string[i]))
// 	{
// 		p_var[j] = string[i];
// 		i++;
// 		j++;
// 	}
// 	p_var[j] = 0;

// 	return(p_var);
// }

// // frees the string it receives and give out a new malloc'd string with the first $-expand made and everything else just copied identically
// char	*expand_var(char *str, char *value, int start)
// {
// 	int	i;
// 	int j;
// 	int	len;
// 	char *cop_str;

// 	len = ft_strlen(value);
// 	i = 0;
// 	j = 0;
// 	cop_str = malloc(sizeof(char) * (ft_strlen(str) + len + 1));
// 	while (str[i] != 0 && i < start)
// 	{
// 		cop_str[i] = str[i];
// 		i++;
// 	}
// 	while (str[i] != 0 && (i - start) < len)
// 	{
// 		cop_str[i] = value[j];
// 		i++;
// 		j++;
// 	}
// 	while (str[i] != 0)
// 	{
// 		cop_str[i] = str[i];
// 		i++;
// 	}
// 	free(str);
// 	str = malloc(sizeof(char) * (ft_strlen(str) + len + 1));
// 	return (str);
// }
