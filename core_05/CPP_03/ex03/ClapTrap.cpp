/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:48:17 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/30 11:03:24 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _hitpoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ClapTrap)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = ClapTrap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &ClapTrap)
{
	std::cout << "ClapTrap assignment operator called" << std::endl;
	if (this!= &ClapTrap)
	{
		this->_name = ClapTrap._name;
		this->_hitpoints = ClapTrap._hitpoints;
		this->_energyPoints = ClapTrap._energyPoints;
		this->_attackDamage = ClapTrap._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called " << this->_name << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
{
	std::cout << "ClapTrap constructor called " << name << std::endl;
	this->_name = name;
	this->_hitpoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

std::string ClapTrap::getName() const
{
	return this->_name;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_hitpoints < 1)
	{
		std::cout << "ClapTrap " << this->_name << " is dead and cannot attack" << std::endl;
		return;
	}
	if (this->_energyPoints < 1)
	{
		std::cout << "ClapTrap " << this->_name << " is out of energy and cannot attack" << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage" << std::endl;
	std::cout << "ClapTrap " << this->_name << " has " << this->_energyPoints << " energy points left" << std::endl;
	return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitpoints < 1)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead" << std::endl;
		return;
	}
	if (this-> _energyPoints < 1)
	{
		std::cout << "ClapTrap " << this->_name << " is out of energy and cannot take damage" << std::endl;
		return;
	}
	this->_hitpoints = this->_hitpoints - amount;
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage" << std::endl;
	std::cout << "ClapTrap " << this->_name << " has " << this->_hitpoints << " hit points left" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitpoints < 1)
	{
		std::cout << "ClapTrap " << this->_name << " is dead and cannot be repaired" << std::endl;
		return;
	}
	if (this->_energyPoints < 1)
	{
		std::cout << "ClapTrap " << this->_name << " is out of energy and cannot be repaired" << std::endl;
		return;
	}
	this->_hitpoints = this->_hitpoints + amount;
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " is repaired for " << amount << " hit points" << std::endl;
	std::cout << "ClapTrap " << this->_name << " has " << this->_hitpoints << " hit points left" << std::endl;
}
