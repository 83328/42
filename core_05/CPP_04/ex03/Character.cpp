/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:29:38 by alimpens          #+#    #+#             */
/*   Updated: 2024/08/02 16:58:15 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character()
{
	//std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string const &name) : _name(name)
{
	//std::cout << "Character string constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character &src) : _name(src._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (src._inventory[i])
		{
			if (_inventory[i])
				delete _inventory[i];
		_inventory[i] = src._inventory[i]->clone();
		}
		else
			_inventory[i] = NULL;
	}
}

Character &Character::operator=(const Character &original)
{
	if (this != &original)
	{
//		_name = original._name;
		for (int i = 0; i < 4; i++)
		{
			if (original._inventory[i])
			{
				if (_inventory[i])
					delete _inventory[i];
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if (original._inventory[i])
			{
				_inventory[i] = original._inventory[i]->clone();
				std::cout << "Deep copy of character created" << std::endl;
			}
			else
				_inventory[i] = NULL;
		}
	}
	//std::cout << "Character assignment operator called" << std::endl;
	return (*this);
}

/* Character &Character::operator=(const Character &original)
{
	if (this != &original)
	{
		for (int i = 0; i < 4; i++)
		{
			if (original._inventory[i])
			{
				if (_inventory[i])
					delete _inventory[i];
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if (original._inventory[i])
			{
				_inventory[i] = original._inventory[i]->clone();
				std::cout << "Deep copy of character created" << std::endl;
			}
			else
				_inventory[i] = NULL;
		}
	}
	//std::cout << "Character assignment operator called" << std::endl;
	return (*this);
} */

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
	//std::cout << "Character destructor called" << std::endl;
}

std::string const & Character::getName() const
{
	return _name;
}

void Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout << "No materia to equip" << std::endl;
		return;
	}
	for  (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			std::cout << "Materia equipped" << std::endl;
			return;
		}
	}
	std::cout << "Inventory full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	if (_inventory[idx])
	{
		_inventory[idx] = 0;
		std::cout << "Materia unequipped" << std::endl;
	}
	else
		std::cout << "No materia to unequip" << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	if (_inventory[idx] == NULL)
	{
		std::cout << "No materia to use" << std::endl;
		return;
	}
	this->_inventory[idx]->use(target);
}
