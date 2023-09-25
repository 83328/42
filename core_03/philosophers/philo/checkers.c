/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:00:46 by alimpens          #+#    #+#             */
/*   Updated: 2023/09/25 16:07:00 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int check_args(int ac, char **av)
{
    int i;

    if(ac <= 4 || ac >= 5)
    {
        printf("Error\n");
        return(0);
    }
    i = 1;
    while(i < ac)
    {
        //write sub1
        if(!check_sub1(av, i))
        {
            printf("Error\n");
            return(0);
        }
        i++;
    }
    return(1);
}
