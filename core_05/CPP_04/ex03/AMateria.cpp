/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:29:16 by alimpens          #+#    #+#             */
/*   Updated: 2024/08/02 16:39:44 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
//	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
//	std::cout << "AMateria string constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &src): _type(src._type)
{
	//std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &original)
{
	if (this != &original)
	{
		_type = original._type;
	}
	//std::cout << "AMateria assignment operator called" << std::endl;
	return (*this);
}

AMateria::~AMateria()
{
	//std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << "AMateria use function called on " << target.getName() << std::endl;
}
