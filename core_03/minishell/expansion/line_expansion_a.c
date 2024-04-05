/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_expansion_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 06:38:57 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/05 16:18:26 by alimpens         ###   ########.fr       */
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

// char	*line_expansion(char *line, t_struct *stru)
// {
// 	char	*line2;
// 	char	*ret;
// 	int		flag;

// 	ret = malloc(sizeof(char));
// 	ret[0] = '\0';
// 	flag = 0;
// 	stru->line_pos = 0;

// 	line2 = line_expansion_once(line, stru);
// 	ret = ft_concat(ret,line2);
// 	write(2,ret, 12);
// 	line2 = line_expansion_once(ret + stru->line_pos, stru);
// 	ret[stru->line_pos] = '\0';
// 	write(2,ret, 12);
// 	ret = ft_concat(ret,line2);

// 	stru->line_pos = 0;
// 	return (ret);
// }

int	len_til_quote(char *str)
{
	int	i;

	i = 0;
	while ((str[i] != 39 && str[i] != 34 && str[i] != 0))
		i++;
	return (i);
}

/* char	*line_expansion(char *line, t_struct *stru)
{
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
		stru->line_pos++;
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
				stru->line_pos += ft_strlen(app_str);
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
				stru->line_pos += ft_strlen(app_str);
			}
			str = ft_concat(str, app_str);
		}
		if (cop_line[i] != 39 && cop_line[i] != 34)
		{
			n = len_til_quote(cop_line + i);
			app_str = ft_substr(cop_line, i, n);
			i += ft_strlen(app_str) - 1;
			str = ft_concat(str, app_str);
		}
		i++;
	}
	free(line);
	free(cop_line);
	return (str);
} */

char	*process_quotes(char *cop_line, char *str, t_struct *stru, int *i)
{
	char	*app_str;

	app_str = NULL;
	if (cop_line[*i] == 39)
	{
		(*i)++;
		app_str = copy_til_squote(cop_line, *i);
		*i += ft_strlen(app_str);
		stru->line_pos += ft_strlen(app_str);
	}
	else if (cop_line[*i] == 34)
	{
		(*i)++;
		app_str = copy_til_dquote(cop_line, *i);
		if (app_str == NULL)
		{
			return (NULL);
		}
		*i += ft_strlen(app_str) + 1;
		app_str = dollars_expansion(app_str, stru);
		stru->line_pos += ft_strlen(app_str);
	}
	str = ft_concat(str, app_str);
	return (str);
}

char	*process_no_quotes(char *cop_line, char *str, int *i)
{
	int		n;
	char	*app_str;

	n = len_til_quote(cop_line + *i);
	app_str = ft_substr(cop_line, *i, n);
	*i += ft_strlen(app_str) - 1;
	str = ft_concat(str, app_str);
	return (str);
}

char	*line_expansion(char *line, t_struct *stru)
{
	char	*cop_line;
	char	*str;
	int		i;

	cop_line = ft_strdup(line);
	i = 0;
	while (cop_line[i] != 0 && cop_line[i] != 39 && cop_line[i] != 34)
	{
		i++;
		stru->line_pos++;
	}
	str = ft_strndup(cop_line, i);
	str = dollars_expansion(str, stru);
	while (cop_line[i] != 0)
	{
		if (cop_line[i] == 39 || cop_line[i] == 34)
			str = process_quotes(cop_line, str, stru, &i);
		if (cop_line[i] != 39 && cop_line[i] != 34)
			str = process_no_quotes(cop_line, str, &i);
		i++;
	}
	free(line);
	free(cop_line);
	return (str);
}
