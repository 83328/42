/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:09:08 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/31 14:23:48 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &to_copy)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = to_copy;
}

WrongCat &WrongCat::operator=(const WrongCat &original)
{
	if (this != &original)
	{
		this->type = original.type;
	}
	std::cout << "WrongCat assignment operator called" << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Chirp Chirp" << std::endl;
}
