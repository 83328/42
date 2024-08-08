/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:50:20 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/30 11:01:44 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_name = "FragTrap default constructor";
	this->_hitpoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &_fragTrap)
{
	*this = _fragTrap;
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &_fragTrap)
{
	std::cout << "FragTrap assignment operator called" << std::endl;
	if (this != &_fragTrap)
	{
		this->_name = _fragTrap._name;
		this->_hitpoints = _fragTrap._hitpoints;
		this->_energyPoints = _fragTrap._energyPoints;
		this->_attackDamage = _fragTrap._attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called " << this->_name << std::endl;
}

FragTrap::FragTrap(const std::string &name)
{
	std::cout << "FragTrap constructor called " << name << std::endl;
	this->_name = name;
	this->_hitpoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->_name << " requests a high five!" << std::endl;
}
