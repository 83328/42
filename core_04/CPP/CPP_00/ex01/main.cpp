/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:17:27 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/22 15:45:05 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main(void)
{
	std::string userInput;
	Phonebook   phonebook;
	
	while (1)
	{
		std::cout << "Enter a command (ADD / SEARCH / EXIT): ";
		getline(std::cin, userInput);
		if (std::cin.eof())
			break ;
		if (!userInput.compare("ADD"))
			phonebook.addContact();
		else if (!userInput.compare("SEARCH"))
			phonebook.searchContact();
		else if (!userInput.compare("EXIT"))
			break ;
		else
			std::cout << "Invalid option" << std::endl;
	}
	return (0);
}
