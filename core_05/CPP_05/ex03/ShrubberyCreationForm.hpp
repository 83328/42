#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &to_copy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &original);
		~ShrubberyCreationForm();

		void execute(Bureaucrat const &executor) const;
};

#endif
