/* Assignment name  : rev_print
Expected files   : rev_print.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays the string in reverse
followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$ */

#include <unistd.h>

int main(int ac, char **av)
{
    int i;
    if (ac == 2)
    {
        while (av[1][i])
            i++;
        while (i)
            write(1, &av[1][--i], 1);
    }
    write(1, "\n", 1);
}

/* int	main(int argc, char *argv[])
{
	int	i = 0;

	if (argc == 2)
	{
		while (argv[1][i])
			i += 1;
		while (i)
			write(1, &argv[1][--i], 1);
	}
	write(1, "\n", 1);
	return (0);
} */


/* 
#include <unistd.h>

char *rev_print(char *str)
{
	int i;
	i = 0;
	while(str[i] != '\0')
		i++;
	i--;
//	while(str[i] != '\0') => wrong in the exam!!!
	while(i >= 0)
	{
		write(1, &str[i], 1);
		i--;
	}
	return(0);
}

int main(void)
{
	char *str = "Hello";
	
	rev_print(str);
}
 */

 char  *rev_print(char *str)
 {
   int len;
  
   len = 0;
   while(str[len] != '\0')
     len++;

	len--;
   while(len >= 0)
   {
     write(1, &str[len], 1);
     len--;
   }
   return (str);
 }

int main(void)
{
	rev_print("rainbow dash");
	write(1, "\n", 1);
	rev_print("Ponies are awesome");
	write(1, "\n", 1);
	rev_print("");
	write(1, "\n", 1);
	return (0);
}

