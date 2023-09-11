/* Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.

'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'

and so on.

Case is not changed.

If the number of arguments is not 1, display only a newline.

Examples:

$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$> */

#include<unistd.h>

int main(int ac, char **av)
{
int i;
i = 0;
if(ac == 2)
{
	while(av[1][i])
	{
		if(av[1][i] >= 'A' && av[1][i] <= 'Z')
			av[1][i] = 'Z'-av[1][i]+ 'A';
		else if(av[1][i] >= 'a' && av[1][i] <= 'z')
			av[1][i] = 'z' - av[1][i] + 'a';
	write(1, &av[1][i], 1);
	i++;
	}
}
write(1, "\n", 1);
return(0);
}

/* #include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;

	if (argc == 2)
	{
		while(argv[1][i]) 
		{
			if(argv[1][i] >= 65 && argv[1][i] <= 90)
			{	
				argv[1][i] = 90 - argv[1][i] + 65;
			}
			else if (argv[1][i] >= 97 && argv[1][i] <= 122)
			{
				argv[1][i] = 122-argv[1][i] + 97;
			}
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write (1,"\n",1);
}	
 */