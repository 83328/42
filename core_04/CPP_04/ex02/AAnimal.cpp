/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:07:54 by alimpens          #+#    #+#             */
/*   Updated: 2024/08/02 11:26:57 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& to_copy)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = to_copy;
}

AAnimal &AAnimal::operator=(const AAnimal &original)
{
	if (this != &original)
	{
		this->_type = original._type;
	}
	std::cout << "AAnimal assignment operator called" << std::endl;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const
{
	return (this->_type);
}

void AAnimal::setType(std::string type)
{
	this->_type = type;
}

