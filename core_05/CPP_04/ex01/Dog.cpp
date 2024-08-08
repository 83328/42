/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:38:49 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/31 16:27:44 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->setType("Dog");
	try
	{
		this->_brain = new Brain();
		std::cout << "Dog brain allocated" << std::endl;
	}
	catch (std::bad_alloc &mem_er)
	{
		std::cerr << "Failed to allocate memory for dog brain" << std::endl;
	}
}

Dog::Dog(const Dog &to_copy) : Animal(to_copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_type = to_copy._type;
	this->_brain = new Brain(*to_copy._brain);
}

Dog &Dog::operator=(const Dog &original)
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
	std::cout << "Dog copy assignment operator called" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof" << std::endl;
}
