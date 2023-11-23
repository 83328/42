/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:44:22 by alimpens          #+#    #+#             */
/*   Updated: 2023/11/23 16:37:29 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void)
{
    // Initialize the shell
    initialize_shell();

    // Main shell loop
    while (1)
    {
        // Display the prompt and get user input
        display_prompt();
        char* user_input = get_user_input();

        // Check for exit command
        if (is_exit_command(user_input)) {
            // Clean up and exit the shell
            free(user_input);
            cleanup_shell();
            break;
        }

        // Execute the user command
        execute_command(user_input);

        // Free the allocated memory for user input
        free(user_input);
    }

    return (0);
}

/* Explanation:

The main function initializes the shell using initialize_shell() and then enters a loop to continuously prompt the user for input and execute commands.

The display_prompt() function is responsible for showing the shell prompt to the user.

The get_user_input() function retrieves the user's input from the command line.

The is_exit_command() function checks if the user entered the exit command (e.g., "exit" or "quit").

The execute_command() function is responsible for parsing and executing the user's command. This function will likely involve dispatching to specific functions for each supported command (e.g., execute_echo, execute_cd, etc.), which you would implement in shell.c.

The loop continues until the user enters the exit command. Once the exit command is detected, the cleanup_shell() function is called to perform any necessary cleanup before exiting the program.

Please note that this is a basic example, and you'll need to implement the actual functionality for each of the functions mentioned above. Additionally, you may need to handle error conditions, memory management, and other aspects of a fully functional shell. */