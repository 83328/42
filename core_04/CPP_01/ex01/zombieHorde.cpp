/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:16:07 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/24 09:48:46 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	int i = 0;
	Zombie* tmp = new Zombie[N];

	while (i < N)
	{
		tmp[i].setName(name);
		tmp[i].announce();
		i++;
	}
	return (tmp);
}