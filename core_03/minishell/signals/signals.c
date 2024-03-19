#include "../minishell.h"

void sigint_handler(int sig) 
{
	if (sig == SIGINT && global_sig == 0)
	{
		rl_replace_line("", 0);  // Clear the current input line
		printf("\n");
		printf("minishell ## ");
	}
	else if (sig == SIGINT && global_sig == 1) //blocking command
	{
		//rl_on_new_line();// Move to a new line
		//rl_redisplay();
		printf("\n");
	}
	else if (sig == SIGINT && global_sig == 2) // heredoc
	{
		global_sig = 4;
		//printf("minishell ## ");
		rl_on_new_line();
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		//write(0, "\n", 1);
	}
}

void	*signal_handling()
{
	signal(SIGINT, sigint_handler); //crtl-c
	signal(SIGQUIT, SIG_IGN); //crtl-backslash
	signal(SIGTSTP, SIG_IGN); //crtl-z
	return (NULL);
}