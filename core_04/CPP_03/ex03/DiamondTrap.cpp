/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:50:50 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/30 12:04:59 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	this->FragTrap::_hitpoints = 100;
	this->ScavTrap::_energyPoints = 50;
	this->FragTrap::_attackDamage = 20;
	
	std::cout << "DiamondTrap " << this->_name << " created!" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap " << this->_name << " is " << ClapTrap::_name << std::endl;
}

int DiamondTrap::getHitPoints() const
{
	return this->FragTrap::_hitpoints;
}

int DiamondTrap::getEnergyPoints() const
{
	return this->ScavTrap::_energyPoints;
}

int DiamondTrap::getAttackDamage() const
{
	return this->FragTrap::_attackDamage;
}
