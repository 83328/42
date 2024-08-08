#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _aFormName;
		bool _aFormSigned;
		const int _gradeToSign;
		const int _gradeToExec;

	public:
		AForm();
		AForm(const std::string &name, int gradeToSign);
		AForm(const std::string &name, int gradeToSign, int gradeToExec);
 
		AForm(const AForm &to_copy);
		AForm &operator=(const AForm &original);
		virtual ~AForm();

		std::string getAFormName() const;
		bool isAFormSigned() const;
		int getGradeToSign() const;
		int getGradeToExec() const;

		void beSigned(const Bureaucrat &bureaucrat);

		virtual void execute(Bureaucrat const &executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("the bureaucrat's grade is too high");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("the bureaucrat's grade is too low");
				}
		};
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("it is not allowed to sign");
				}
		};
		class ExecTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("the form's legally not allowed to be executed");
				}
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &aForm);

#endif
