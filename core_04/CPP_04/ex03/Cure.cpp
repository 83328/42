/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:30:05 by alimpens          #+#    #+#             */
/*   Updated: 2024/08/02 16:28:54 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	//std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(Cure const & src) : AMateria(src)
{
	//std::cout << "Cure copy constructor called" << std::endl;
	*this = src;
}

Cure& Cure::operator=(Cure const &original)
{
	if (this != &original)
	{
		this->_type = original._type;
	}
	return *this;
}

std::string const & Cure::getType() const
{
	return this->_type;
}

Cure::~Cure()
{
	//std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
