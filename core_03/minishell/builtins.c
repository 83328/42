#include "minishell.h"


//
void	builtins(int len, char **reassembled_commands, char **envp, t_struct *stru)
{
    int     i;
    char    comm_no_args;

    i = 0;
    while (reassembled_commands[i])
    {
        comm_no_args = get_comm(reassembled_commands[i]) //gets the first word (everything until first space)
        if (strncmp("",comm_no_args) ==)
        {} // run builtin and return exit status
        else if(strncmp("",comm_no_args) ==)
        {}
        else if(strncmp("",comm_no_args) ==)
        {}
        i++;
    }
}