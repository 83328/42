/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:08:06 by alimpens          #+#    #+#             */
/*   Updated: 2024/08/02 14:21:30 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat() : AAnimal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->setType("Cat");
	try
	{
		this->_brain = new Brain();
		std::cout << "Brain allocated" << std::endl;
	}
	catch (std::bad_alloc &e)
	{
		std::cerr << "Failed to allocate memory for brain: " << e.what() << std::endl;
	}
}

Cat::Cat(const Cat &to_copy) : AAnimal(to_copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_type = to_copy._type;
	this->_brain = new Brain(*to_copy._brain);
}

Cat &Cat::operator=(const Cat &original)
{
	if (this != &original)
	{
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
