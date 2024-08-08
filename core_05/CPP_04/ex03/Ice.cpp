/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:31:18 by alimpens          #+#    #+#             */
/*   Updated: 2024/08/02 16:24:05 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
//	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(Ice const & src) : AMateria(src)
{
//	std::cout << "Ice copy constructor called" << std::endl;
    *this = src;
}

Ice& Ice::operator=(Ice const &original)
{
    if (this != &original)
    {
        this->_type = original._type;
    }
    return *this;
}

Ice::~Ice()
{
//	std::cout << "Ice destructor called" << std::endl;
}

std::string const & Ice::getType() const
{
    return this->_type;
}

AMateria* Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
