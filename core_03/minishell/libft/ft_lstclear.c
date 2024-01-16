/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgacic <dgacic@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 02:29:22 by dgacic            #+#    #+#             */
/*   Updated: 2023/11/14 02:29:23 by dgacic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*body;
	t_list	*temp;

	if (!lst || !(*del))
		return ;
	body = *lst;
	while (body != NULL)
	{
		temp = body;
		del(body->content);
		body = body->next;
		free(temp);
	}
	*lst = NULL;
}
