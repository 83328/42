/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:38:49 by alimpens          #+#    #+#             */
/*   Updated: 2024/08/02 14:22:00 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : AAnimal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->setType("Dog");
	try
	{
		this->_brain = new Brain();
		std::cout << "Dog brain created" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

Dog::Dog(const Dog &to_copy) : AAnimal(to_copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_type = to_copy._type;
	this->_brain = new Brain(*to_copy._brain);
}

Dog &Dog::operator=(const Dog &original)
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
