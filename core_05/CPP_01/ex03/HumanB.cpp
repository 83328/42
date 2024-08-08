/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:59:09 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/24 10:36:40 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB()
{
}

HumanB::HumanB(std::string name)
{
	_name = name;
	_weapon = NULL;
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

void HumanB::attack()
{
	if (this->_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

HumanB::~HumanB()
{

}