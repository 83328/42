/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:07:54 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/31 16:14:07 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &to_copy)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = to_copy;
}

Animal &Animal::operator=(const Animal &original)
{
	if (this != &original)
	{
		this->_type = original._type;
	}
	std::cout << "Animal assignment operator called" << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return (this->_type);
}

void Animal::setType(std::string type)
{
	this->_type = type;
}

void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}
