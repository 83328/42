/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:01:22 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/24 13:39:13 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl has been created" << std::endl;
}

void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You did not put enough bacon in my burger! If you did, I would not be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I have been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl has been destroyed" << std::endl;
}

void    Harl::harlFilter( std::string level )
{
	int i = 0;

	void (Harl::*functions[]) (void) = 
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	std::string levels[] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	while (i < 4)
	{
		if (levels[i] == level)
			break;
		i++;
	}
	if (i == 4)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	else
	{
		switch (i)
		{
			case 0:
				std::cout << "[ 1." << levels[0] << " ]" << std::endl;
				(this->*functions[0])();
			case 1:
				std::cout << "[ 2." << levels[1] << " ]" << std::endl;
				(this->*functions[1])();
			case 2:
				std::cout << "[ 3." << levels[2] << " ]" << std::endl;
				(this->*functions[2])();
			case 3:
				std::cout << "[ 4." << levels[3] << " ]" << std::endl;
				(this->*functions[3])();
				break;
			default:
				std::cout << "[ Unknown level ]" << std::endl;
		}
	}
}
