/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:28:06 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/22 15:28:57 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    char *str;
    
    if(ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    else
    {
        for(int i = 1; i < ac; i++)
        {
            str = av[i];
            while(*str)
            {
                std::cout << (char)toupper(*str);
                str++;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}