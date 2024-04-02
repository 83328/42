/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_expansion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:40:12 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/27 17:02:10 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*expand_var(char *string, char *value, int start, int var_len);
char	*get_p_var(char *string, int start);
char	*dollars_expansion(char *string, t_struct *stru);

// int	contains_quotes(char *line)
// {
// 	int	ret;
// 	int	i;

// 	i = 0;
// 	ret = 0;

// 	while (line[i])
// 	{
// 		if (line[i] == 39 || line[i] == 34)
// 			ret = 1;
// 		i++;
// 	}
// 	return (ret);
// }

// char	*line_expansion_new(char *line, t_struct *stru)
// {
// 	int		qflag;
// 	int		i;
// 	char	*str;

// 	qflag = 0;
// 	if (contains_quotes(line))
// 		qflag = 1;
// 	while (qflag == 1)
// 	{
// 		qflag == 0;
// 		str = 
// 		str = line_expansion_once(line, stru);
// 		while (line[i])
// 		{
// 			if (line[i] == 39 || line[i] == 39)
// 				qflag = 1;
// 		}
// 	}
// 	return (line);
// }


char	*line_expansion(char *line, t_struct *stru)
{
	// printf("line_expansion%s\n", line);
	char	*cop_line;
	char	*str;
	char	*app_str;
	int		n;
	int		i;

	cop_line = ft_strdup(line);
	i = 0;
	n = 0;
	while (cop_line[i] != 0 && cop_line[i] != 39 && cop_line[i] != 34)
	{
		n++;
		i++;
	}
	str = ft_strndup(cop_line, n);
	str = dollars_expansion(str, stru);
	n = 0;
	while (cop_line[i] != 0)
	{
		if (cop_line[i] == 39 || cop_line[i] == 34)
		{
			if (cop_line[i] == 39)
			{
				i++;
				app_str = copy_til_squote(cop_line, i);
				i += ft_strlen(app_str);
			}
			else if (cop_line[i] == 34)
			{
				i++;
				app_str = copy_til_dquote(cop_line, i);
				if (app_str == NULL)
				{
					return (NULL);
				}
				i += ft_strlen(app_str) + 1;
				app_str = dollars_expansion(app_str, stru);
			}
			str = ft_concat(str, app_str);
			n = i;
		}
		if (cop_line[i] != 39 && cop_line[i] != 34)
		{
			app_str = ft_str_revndup(cop_line, n);
			i += ft_strlen(app_str) - 1;
			str = ft_concat(str, app_str);
		}
		i++;
	}
	free(line);
	free(cop_line);
	return (str);
}

char	*dollars_expansion(char *string, t_struct *stru)
{
	char	*p_var;
	char	*p_val;
	int		i;
	int		still_dollars;

	i = 0;
	still_dollars = 1;
	while (still_dollars == 1)
	{
		still_dollars = 0;
		i = 0;
		while (string[i] != 0)
		{
//			if (string[i] == '$' && contains_echo(string) == 0)
			if (string[i] == '$')
			{
				still_dollars = 1;
				p_var = get_p_var(string, i + 1);
				p_val = ft_getenv(p_var, stru->env_copy);
				if (p_val != NULL)
				{
					string = expand_var(string, p_val, i, ft_strlen(p_var));
					break ;
				}
				else
				{
					string = ft_strdup("");
					break ;
				}
			}
			else
				i++;
		}
	}
	return (string);
}

/* int	contains_echo(char *str)
{
	if (ft_strncmp(str, "echo", 4) == 0)
	{
		return (1);
	}
	return (0);
} */

char	*expand_var(char *str, char *value, int start, int var_len)
{
	int		i;
	int		j;
	int		val_len;
	char	*cop_line;

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
	while (j < (int)((ft_strlen(cop_line) - var_len - 1 - start)))
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
	j = 0;
	var_len = 0;
	while (string[i] != 0 && (string[i] != ' ' && string[i] != 't' && string[i] != 'n' && string[i] != 'r' && string[i] != 'v' && string[i] != 'f'))
	{
		var_len++;
		i++;
	}
	p_var = malloc(sizeof(char *) * (var_len + 1));
	i = start;
	while (string[i] != 0 && (string[i] != ' ' && string[i] != 't' && string[i] != 'n' && string[i] != 'r' && string[i] != 'v' && string[i] != 'f'))
	{
		p_var[j] = string[i];
		i++;
		j++;
	}
	p_var[j] = 0;
	return (p_var);
}
