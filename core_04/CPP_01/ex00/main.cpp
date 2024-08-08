/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:56:24 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/24 15:20:46 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *tmp = newZombie("Hendrik");
	
	tmp->announce();
	delete tmp;

	randomChump("Charlotte");
	return (0);
}
