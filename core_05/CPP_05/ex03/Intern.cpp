/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:51:58 by alimpens          #+#    #+#             */
/*   Updated: 2024/08/07 09:47:34 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{

}

Intern::~Intern()
{

}

Intern::Intern(const Intern &to_copy)
{
	*this = to_copy;
}

Intern &Intern::operator=(const Intern &original)
{
	(void)original;
	return (*this);
}

AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	size_t i = 0;
	while (i < 3 && formName != formNames[i])
		i++;
	switch (i)
	{
		case 0:
			std::cout << "Intern creates " << formName << std::endl;
			return (new ShrubberyCreationForm(formTarget));
			break;
		case 1:
			std::cout << "Intern creates " << formName << std::endl;
			return (new RobotomyRequestForm(formTarget));
			break;
		case 2:
			std::cout << "Intern creates " << formName << std::endl;
			return (new PresidentialPardonForm(formTarget));
			break;
		default:
			std::cout << "Intern cannot create " << formName << std::endl;
			return (NULL);
			break;
	}
}
