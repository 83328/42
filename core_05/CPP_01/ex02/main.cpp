/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:56:24 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/23 16:54:40 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string string = "HI, THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "The address of the string variable: " << &string << std::endl;
	std::cout << "The address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "The address held by stringREF: " << &stringREF << std::endl;

	std::cout << "The value of the string variable: " << string << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;
}
