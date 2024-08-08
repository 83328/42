/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:48:58 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/29 14:34:09 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void) 
{
	ClapTrap aaa("Monster 1");
	ClapTrap bbb("Monster 2");
	ScavTrap ccc("Guardian 1");
	ScavTrap ddd("Guardian 2");

	std::cout << '\n';
	aaa.beRepaired(3);
	std::cout << '\n';
	aaa.attack("Monster 2");
	std::cout << '\n';
	bbb.takeDamage(4);
	std::cout << '\n';
	aaa.attack("Monster 2");
	std::cout << '\n';
	bbb.takeDamage(6);
	std::cout << '\n';
	bbb.attack("Monster 1");
	std::cout << '\n';
	aaa.takeDamage(0);
	std::cout << '\n';
	aaa.attack("Monster 2");
	std::cout << '\n';
	bbb.takeDamage(4);
	std::cout << '\n';

	// Testing ScavTrap specific functionalities
	ccc.attack("Monster 1");
	std::cout << '\n';
	ddd.takeDamage(5);
	std::cout << '\n';
	ccc.guardGate();
	std::cout << '\n';
	ddd.beRepaired(10);
	std::cout << '\n';

	return (0);
}
