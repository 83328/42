/*
Hello, World!

Write a function that prints "Hello, World!" followed by a newline.
Make a main function to call this function.
Your project must be written in accordance with the Norm of 42 (except for the 42 header).

Function:
	name:		hello_world
	arguments:	void
	returns:	void

Allowed external functions:
	write from <unistd.h>

Compile:
	cc -Wall -Wextra -Werror 01_hello_world_solution.c -o hello_world

Run:
	./hello_world
*/

#include <unistd.h>

void	hello_world(void)
{
	write (1, "Hello, World!\n", 14);
}

int	main(void)
{
	hello_world();
	return (0);
}
