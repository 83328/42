/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:08:06 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/31 17:03:41 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
	try
	{
		this->_brain = new Brain();
	}
	catch (std::bad_alloc &e)
	{
		std::cerr << "Failed to allocate memory for brain" << std::endl;
	}
}

Cat::Cat(const Cat &to_copy) : Animal(to_copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_type = to_copy._type;
	this->_brain = new Brain(*to_copy._brain);
}

Cat &Cat::operator=(const Cat &original)
{
	if (this != &original)
	{
		Animal::operator=(original);
		this->_type = original._type;
		if (this->_brain != NULL)
		{
			delete this->_brain;
		}
		this->_brain = new Brain(*original._brain);
	}
	std::cout << "Cat copy assignment operator called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}
