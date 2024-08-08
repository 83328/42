/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:43:30 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/30 12:04:00 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

int main()
{
	// Create a DiamondTrap instance
	DiamondTrap diamond("Diamond");

	// Test the attack function inherited from ScavTrap
	diamond.attack("target");

	// Test the whoAmI function
	diamond.whoAmI();

	// Test the highFivesGuys function inherited from FragTrap
	diamond.highFivesGuys();

	// Display the attributes
	std::cout << "Hit points: " << diamond.getHitPoints() << std::endl;
	std::cout << "Energy points: " << diamond.getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << diamond.getAttackDamage() << std::endl;

	return 0;
}