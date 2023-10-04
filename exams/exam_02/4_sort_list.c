/* Assignment name  : sort_list
Expected files   : sort_list.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following functions:

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function
pointer cmp to select the order to apply, and returns a pointer to the
first element of the sorted list.

Duplications must remain.

Inputs will always be consistent.

You must use the type t_list described in the file list.h
that is provided to you. You must include that file
(#include "list.h"), but you must not turn it in. We will use our own
to compile your assignment.

Functions passed as cmp will always return a value different from
0 if a and b are in the right order, 0 otherwise.

For example, the following function used as cmp will sort the list
in ascending order:

int ascending(int a, int b)
{
	return (a <= b);
} */

#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list* tmp = lst;
	int	swap;

	while(lst->next)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}

/* #include <stdlib.h>
#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int	swap;
	t_list	*tmp;

	tmp = lst;
	while(lst->next != NULL)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}
 */




/* t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list* tmp;
	int	swap;

	tmp = lst;
	while(lst->next)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}

int ascending(int a, int b)
{
	return (a <= b);
}

void	printlist(t_list *lst)
{
	t_list *cur;

	cur = lst;
	while (cur)
	{
		printf("%d\n", cur->data);
		cur = cur->next;
	}
}

int	main(void)
{
	int	int1	= 201;
	int	int2	= 93;
	int	int3	= 2;

	t_list *aa = malloc(sizeof(t_list));
	aa->data = int1;

	t_list *bb = malloc(sizeof(t_list));
	aa->next = bb;
	bb->data = int2;

	t_list *cc = malloc(sizeof(t_list));
	bb->next = cc;
	cc->data = int3;
	//cc->next = 0;

	t_list *cur = aa;
	
	printlist(cur);
	printf("\n");
	cur = sort_list(aa, ascending);
	printlist(cur);
} */
