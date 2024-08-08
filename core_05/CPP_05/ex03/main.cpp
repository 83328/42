/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:57:23 by alimpens          #+#    #+#             */
/*   Updated: 2024/08/07 10:37:36 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		std::cout << "=== Test 1: Bureaucrat Creation ===" << std::endl;
		Bureaucrat dennis("Dennis", 1);
		std::cout << "Created Bureaucrat: " << dennis << std::endl;

		std::cout << "\n=== Test 2: Form Creation ===" << std::endl;
		ShrubberyCreationForm shrubbery("Frank");
		RobotomyRequestForm robotomy("Mac");
		PresidentialPardonForm pardon("Dee");
		std::cout << "Created Forms: Shrubbery, Robotomy, Pardon" << std::endl;

		std::cout << "\n=== Test 3: Signing Forms ===" << std::endl;
		dennis.signForm(shrubbery);
		dennis.signForm(robotomy);
		dennis.signForm(pardon);

		std::cout << "\n=== Test 4: Executing Forms ===" << std::endl;
		dennis.executeForm(shrubbery);
		dennis.executeForm(robotomy);
		dennis.executeForm(pardon);

		std::cout << "\n=== Test 5: Intern Form Creation ===" << std::endl;
		Intern intern;
		AForm *rrf;
		AForm *rf;
		AForm *f;

		rrf = intern.makeForm("robotomy request", "Bender");
		rf = intern.makeForm("shrubbery creation", "Bender");
		f = intern.makeForm("presidential pardon", "Bender");

		std::cout << "Intern created forms: " << std::endl;
		std::cout << *rrf << std::endl;
		std::cout << *rf << std::endl;
		std::cout << *f << std::endl;

		std::cout << "\n=== Test 6: Deleting Intern Forms ===" << std::endl;
		delete rrf;
		delete rf;
		delete f;
		std::cout << "Deleted Intern created forms" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}
	catch(const AForm::GradeTooHighException& e)
	{
		std::cerr << "GradeTooHighException caught: " << e.what() << '\n';
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cerr << "GradeTooLowException caught: " << e.what() << '\n';
	}

	return 0;
}

/* #include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		// Create a Bureaucrat
		Bureaucrat dennis("Dennis", 1);

		// Create forms
		ShrubberyCreationForm shrubbery("Frank");
		RobotomyRequestForm robotomy("Mac");
		PresidentialPardonForm pardon("Dee");

		// Bureaucrat signs the forms
		dennis.signForm(shrubbery);
		dennis.signForm(robotomy);
		dennis.signForm(pardon);

		// Bureaucrat executes the forms
		dennis.executeForm(shrubbery);
		dennis.executeForm(robotomy);
		dennis.executeForm(pardon);

		// Create an Intern
		Intern intern;
		AForm *rrf;
		AForm *rf;
		AForm *f;

		// Create forms using the Intern
		rrf = intern.makeForm("robotomy request", "Bender");
		rf = intern.makeForm("shrubbery creation", "Bender");
		f = intern.makeForm("presidential pardon", "Bender");
		
		delete rrf;
		delete rf;
		delete f;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const AForm::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
} */
