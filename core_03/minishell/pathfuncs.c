/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfuncs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:41:19 by dgacic            #+#    #+#             */
/*   Updated: 2024/01/30 10:32:52 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void perror_exit(const char *message)
{
    perror(message);
    exit(EXIT_FAILURE);
}

char    *alloc_full_path(const char *folder, const char *file)
{
    size_t  path_len;
    size_t  file_len;
    char    *full_path;
    path_len = ft_strlen(folder);
    file_len = ft_strlen(file);
    if ((path_len + file_len + 2) > (PATH_MAX + 1))
    {
        perror_exit("Path exceeds PATH_MAX length\n");
        return (NULL);
    }
    full_path = malloc((path_len + file_len + 2) * sizeof(char));
    if (!full_path)
        return (NULL);
    ft_strcpy(full_path, folder);
    ft_strcat(full_path, "/");
    ft_strcat(full_path, file);
    return (full_path);
}
char    *find_command_path(const char *file, char *PATH)
{
    char    *path;
    char    *full_path;
    char    **split_path;
    int     i;
    i = 0;
    path = ft_strdup(PATH);
    split_path = ft_split(path, ':');
    free(path);
    full_path = NULL;
    while (split_path[i] != 0)
    {
        full_path = alloc_full_path(split_path[i], file);
        if (full_path != NULL && access(full_path, X_OK) == 0)
            return (full_path);
        free(full_path);
        i++;
    }
    i = 0;
    while (split_path[i] != 0)
        free(split_path[i++]);
    free(split_path);
    return (NULL);
}
int mod_execvp(const char *file, char *const argv[], char *PATH)
{
    char    *full_path;
    if (!file || !argv)
    {
        printf("Invalid arguments.\n");
        return (-1);
    }
    full_path = find_command_path(file, PATH);
    if (full_path == NULL)
        ;
    else if (access(full_path, X_OK) != 0)
    {
        perror_exit("no file permission: ");
    }
    else if (execve(full_path, argv, NULL) == -1)
    {
        free(full_path);
        perror_exit("execve");
    }
    free(full_path);
    return (-1);
}
char    *path_from_env(char *path_word, char **env)
{
    int     i;
    int     j;
    char    *sub;
    i = 0;
    while (env[i])
    {
        j = 0;
        while (env[i][j] && env[i][j] != '=')
            j++;
        sub = ft_substr(env[i], 0, j);
        if (ft_strncmp(sub, path_word, ft_strlen(sub)) == 0)
        {
            free(sub);
            return (env[i] + j + 1);
        }
        free(sub);
        i++;
    }
    return (NULL);
}
