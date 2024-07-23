/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:17:32 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/22 15:32:28 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::saveContact(const std::string& firstname, const std::string& lastname, const std::string& nickname, const std::string& phoneNumber, const std::string& darkestSecret)
{
	_firstname = firstname;
	_lastname = lastname;
	_nickname = nickname;
	_phoneNumber = phoneNumber;
	_darkestSecret = darkestSecret;
}

void Contact::printDetails() const
{
	std::cout << "First name       : " << _firstname << std::endl
			  << "Last name        : " << _lastname << std::endl
			  << "Nickname         : " << _nickname << std::endl
			  << "Phone number     : " << _phoneNumber << std::endl
			  << "Darkest Secret   : " << _darkestSecret << std::endl;
}
