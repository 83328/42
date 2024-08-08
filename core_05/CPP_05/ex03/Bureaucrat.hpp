#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string _bureaucratName;
		int _bureaucratGrade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &to_copy);
		Bureaucrat &operator=(const Bureaucrat &original);
		~Bureaucrat();

		std::string getBureaucratName() const;
		int getBureaucratGrade() const;

		void incrementGrade();
		void decrementGrade();

		void signForm(AForm &form);
		void executeForm(AForm const &form);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("The bureaucrat's grade is too high");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("The bureaucrat's grade is too low");
				}
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &to_print);

#endif