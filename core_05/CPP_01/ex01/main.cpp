/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:56:24 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/24 09:56:33 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cout << "Command : ./Zombie [number] [name]";
		std::exit(0);
	}
	int numZombies = atoi(argv[1]);
	Zombie *tmp = zombieHorde(numZombies, argv[2]);

	for (int i = 0; i < numZombies; i++)
	{
		std::cout << "[" << i << "]";
		tmp[i].announce();
	}

	delete[] tmp;
	return 0;
}
