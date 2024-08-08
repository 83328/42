#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &to_copy);
		Intern &operator=(const Intern &original);

		AForm *makeForm(std::string formName, std::string formTarget);
		~Intern();
};

#endif
