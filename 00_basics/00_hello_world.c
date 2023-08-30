/*
Hello, World!

Write a program that prints "Hello, World!" followed by a newline.
Your project must be written in accordance with the Norm of 42 (except for the 42 header).

Allowed functions:
	write from <unistd.h>

Compile:
	cc -Wall -Wextra -Werror 00_hello_world.c -o hello_world

Run:
	./hello_world
*/

#include <unistd.h>

int main(void)
{
	write(1, "Hello World", 11);
	write(1, "\n", 1);
}