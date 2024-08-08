/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:08:06 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/31 14:49:33 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &to_copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = to_copy;
}

Cat &Cat::operator=(const Cat &original)
{
	if (this != &original)
	{
		this->type = original.type;
	}
	std::cout << "Cat assignment operator called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}
