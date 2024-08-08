/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:57:23 by alimpens          #+#    #+#             */
/*   Updated: 2024/08/07 10:32:53 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		// Create a Bureaucrat
		/*
		ShrubberyCreationForm: Required grades: sign 145, exec 137
		RobotomyRequestForm: Required grades: sign 72, exec 45
		PresidentialPardonForm: Required grades: sign 25, exec 5
		*/
		Bureaucrat dennis("Dennis", 1);

		// Create forms
		ShrubberyCreationForm shrubbery("Frank");
		RobotomyRequestForm robotomy("Mac");
		PresidentialPardonForm pardon("Dee");
		std::cout << std::endl;

		// Bureaucrat signs the forms
		dennis.signForm(shrubbery);
		dennis.signForm(robotomy);
		dennis.signForm(pardon);
		std::cout << std::endl;

		// Bureaucrat executes the forms
		dennis.executeForm(shrubbery);
		std::cout << std::endl;
		dennis.executeForm(robotomy);
		std::cout << std::endl;
		dennis.executeForm(pardon);
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
