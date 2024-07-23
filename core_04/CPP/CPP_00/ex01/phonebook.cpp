/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:23:52 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/23 10:04:59 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook()
{
	_contact_index = 0;
}

Phonebook::~Phonebook() {}

void get_data(std::string &data)
{
	if (std::getline(std::cin, data).eof())
	{
		std::cout << std::endl;
		std::exit(0);
	}
}

void displayTable(Contact contacts[MAX_CONTACTS])
{
	const char* horizontalBorder = "=";
	const char* verticalBorder = "|";
	const char* cornerTopLeft = "╔";
	const char* cornerTopRight = "╗";
	const char* cornerBottomLeft = "╚";
	const char* cornerBottomRight = "╝";
	const char* teeLeft = "╠";
	const char* teeRight = "╣";
	const char* Filler = "-";

	std::cout << std::endl;
	std::cout << cornerTopLeft << std::setfill(horizontalBorder[0]) << std::setw(51) << cornerTopRight << std::endl;
	std::cout << verticalBorder << std::setw(10) << std::left << " Index" << verticalBorder
			  << std::setw(12) << "First Name" << verticalBorder
			  << std::setw(11) << "Last Name" << verticalBorder
			  << std::setw(10) << "Nickname" << verticalBorder << std::endl;
	std::cout << teeLeft << std::setfill(Filler[0]) << std::setw(51) << teeRight << std::endl;

	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		std::cout << verticalBorder << std::setw(9) << std::right << i << " " << verticalBorder;
		std::string firstName = contacts[i].getFirstName().length() > 10 ? contacts[i].getFirstName().substr(0, 9) + "." : contacts[i].getFirstName();
		std::string lastName = contacts[i].getLastName().length() > 10 ? contacts[i].getLastName().substr(0, 9) + "." : contacts[i].getLastName();
		std::string nickName = contacts[i].getNickName().length() > 10 ? contacts[i].getNickName().substr(0, 9) + "." : contacts[i].getNickName();

		std::cout << std::setw(11) << std::right << firstName << verticalBorder
				  << std::setw(10) << lastName << verticalBorder
				  << std::setw(10) << nickName << verticalBorder << std::endl;
	}
	std::cout << cornerBottomLeft << std::setfill(horizontalBorder[0]) << std::setw(51) << cornerBottomRight << std::endl;
}

void Phonebook::addContact()
{
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	while (1)
	{
		std::cout << "Enter first name: ";
		get_data(firstname);
		if (!isalpha(firstname[0]))
		{
			std::cout << "Needs to start with a letter" << std::endl;
			continue;
		}
		if (firstname[0])
			break;
	}

	while (1)
	{
		std::cout << "Enter last name: ";
		get_data(lastname);
		if (!isalpha(lastname[0]))
		{
			std::cout << "Needs to start with a letter" << std::endl;
			continue;
		}
		if (lastname[0])
			break;
	}

	while (1)
	{
		std::cout << "Enter nickname: ";
		get_data(nickname);
		if (!isalpha(nickname[0]))
		{
			std::cout << "Needs to start with a letter" << std::endl;
			continue;
		}
		if (nickname[0])
			break;
	}

	while (1)
	{
		std::cout << "Enter phone number: ";
		get_data(phone_number);
		if (!isdigit(phone_number[0]))
		{
			std::cout << "Needs to start with a digit" << std::endl;
			continue;
		}
		if (phone_number[0])
			break;
	}

	while (1)
	{
		std::cout << "Enter darkest secret: ";
		get_data(darkest_secret);
		if (!darkest_secret[0])
			std::cout << "Type something" << std::endl;
		else
		{
			if (darkest_secret[0] == 32)
				std::cout << "We need more than that..." << std::endl;
			else
				break;
		}
	}
		_contacts[_contact_index].saveContact(firstname, lastname, nickname, phone_number, darkest_secret);

	if (_contact_index >= MAX_CONTACTS)
	{
		_contact_index = 0;
	}
	else
		_contact_index++;
}

bool isValidIndex(const std::string& index, int& validIndex)
{
	if (index.length() == 1 && '0' <= index[0] && index[0] <= '7')
	{
		validIndex = index[0] - '0';
		return true;
	}
	return false;
}

void Phonebook::searchContact()
{
	std::string index;
	int validIndex;

	if (_contact_index == 0)
	{
		std::cout << "Add a contact" << std::endl;
		return;
	}
	displayTable(_contacts);

	bool validSelection = false;
	while (!validSelection)
	{
		std::cout << "Enter search index (0-7): ";
		get_data(index);

		if (isValidIndex(index, validIndex))
		{
			if (_contacts[validIndex].getFirstName().empty())
			{
				std::cout << "Invalid index" << std::endl;
			}
			else
			{
				_contacts[validIndex].printDetails();
				validSelection = true;
			}
		}
		else
		{
			std::cout << "Invalid index" << std::endl;
		}
	}
}
