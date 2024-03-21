#include "../minishell.h"

char	*expand_var(char *string, char *value, int start, int var_len);
char	*get_p_var(char *string, int start);
char	*dollars_expansion(char *string, t_struct *stru);

char    *line_expansion(char *line, t_struct *stru)
{
	char	*cop_line;
	char	*str;
	char 	*app_str;
	int		n;
	int		i;

	cop_line = ft_strdup(line);

	i = 0;
	n = 0;
	while(cop_line[i] != 0 && cop_line[i] != 39 && cop_line[i] != 34) //not null, single quote, double quote
	{
		n++;
		i++;
	}
	printf("back-2 -->%s<--\n", cop_line);
	str = ft_strndup(cop_line, n);
	printf("back-1 -->%s<--\n", str);
	str = dollars_expansion(str, stru);
	n = 0;
	while(cop_line[i] != 0)
	{
		if (cop_line[i] == 39 || cop_line[i] == 34 ) //single or double quotes
		{
			if (cop_line[i] == 39)
			{
				i++;
				app_str = copy_til_squote(cop_line, i);
				i += ft_strlen(app_str) ; //-0 casue Nullterminator
			}
			else if (cop_line[i] == 34)
			{
				i++;
				app_str = copy_til_dquote(cop_line, i);
				i += ft_strlen(app_str) + 1; //-0 casue Nullterminator
				app_str = dollars_expansion(app_str, stru);
			}
			str = ft_concat(str, app_str);
//			n = i;
		}
		i++;
	}
//	app_str = ft_str_revndup(cop_line, n); //
//	str = ft_concat(str,app_str);

	printf("back-0 -->%s<--\n", str);
	return(str);
}

char	*dollars_expansion(char *string, t_struct *stru)
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
				p_val = ft_getenv(p_var, stru->env_copy);
				if (p_val != NULL)
				{
					string = expand_var(string, p_val, i, ft_strlen(p_var)); // free the string it receives and give out a new string with only the first $-expand made
					break;
				}
				else
				{
					string = ft_strdup(""); // free the string it receives and give out a new string with only the first $-expand made
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
	char *cop_line;

	val_len = ft_strlen(value);
	i = 0;
	j = 0;
	cop_line = ft_strdup(str);
	free(str);
    str = malloc(sizeof(char) * (ft_strlen(cop_line) + val_len + 1));
	while (i < start)
	{
		str[i] = cop_line[i];
		i++;
	}
	while (i < val_len + start)
	{
		str[i] = value[j];
		i++;
		j++;
	}
	j = 0;
	while (j < (int)((ft_strlen(cop_line) - var_len - 1 - start)) )
	{
		str[i] = cop_line[j + start + var_len + 1];
		i++;
		j++;
	}
	str[i] = 0;
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
	while(string[i] != 0 && (string[i] != ' ' && string[i] != 't' && string[i] != 'n' && string[i] != 'r' && string[i] != 'v' && string[i] != 'f')) //not "\0" or space
	{
		var_len++;
		i++;
	}
	p_var = malloc(sizeof(char *) * (var_len + 1));
	i = start;
	j = 0;
	while(string[i] != 0 && (string[i] != ' ' && string[i] != 't' && string[i] != 'n' && string[i] != 'r' && string[i] != 'v' && string[i] != 'f'))
	{
		p_var[j] = string[i];
		i++;
		j++;
	}
	p_var[j] = 0;

	return(p_var);
}
