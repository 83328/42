/* Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2); */

#include<stdio.h>
#include<string.h>

int    ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	while(s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return(s1[i] - s2[i]);
}

int main(int ac, char **av)
{
int val;
int val2;
if(ac == 3)
{
	val = ft_strcmp(av[1], av[2]);
	val2 = strcmp(av[1],av[2]);
	printf("own function   : %i\n", val);
	printf("strcmp function: %i\n", val2);
}
printf("\n");
}

/* int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
} */

/* 
int main(int ac, char **av)
{
int i = ft_strcmp(av[1], av[2]);
int j = 0;
j = strcmp(av[1], av[2]);
printf("My function: %i\n", i);
printf("Built-in: %i\n", j);
}
*/

/* -----------------------------------------------------------

int    ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	
	while(s1[i] && s2[i])
	{
		if(s1[i] == s2[i])
			i++;
		else
			break;
	}

	return(s1[i] - s2[i]);
} */