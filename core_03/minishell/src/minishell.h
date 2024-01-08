/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:45:15 by alimpens          #+#    #+#             */
/*   Updated: 2023/12/05 11:29:56 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKENS 100
#define MAX_TOKEN_SIZE 100

//minishell.c
void parse_input(char *input, char **tokens);
void execute_command(char **args, int input_fd, int output_fd);
int handle_builtin(char **args);
void handle_signal(int signo);
int main();
/* 
void initialize_shell();
void display_prompt();
char* get_user_input();
void execute_command(char** command);
void cleanup_shell();
 */

//cd.c

//echo.c
void echo_command(const char* input);

//env.c

//exit.c
int is_exit_command(const char* input);

//export.c

//pwd.c
void pwd_command();

//unset.c


#endif