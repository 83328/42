/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:01:22 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/24 11:33:41 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl has been created" << std::endl;
}

void Harl::debug()
{
	std::cout << "1. I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "2. I cannot believe adding extra bacon costs more money. You did not put enough bacon in my burger! If you did, I would not be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "3. I think I deserve to have some extra bacon for free. I have been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
	std::cout << "4. This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl has been destroyed" << std::endl;
}

void Harl::complain(std::string level)
{
	int i = 0;

	void (Harl::*f[])() = 
	{
		&Harl::debug, 
		&Harl::info, 
		&Harl::warning, 
		&Harl::error, 
	};

std::string levels[] = 
	{
		"DEBUG", 
		"INFO", 
		"WARNING", 
		"ERROR", 
	};

	while (i < 4)
	{
		if (level == levels[i])
		{
			(this->*f[i])();
			return;
		}
		i++;
	}	
}
