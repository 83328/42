/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:01:45 by alimpens          #+#    #+#             */
/*   Updated: 2024/08/07 09:47:40 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{

};

Bureaucrat::~Bureaucrat()
{

};

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _bureaucratName(name), _bureaucratGrade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
};

Bureaucrat::Bureaucrat(const Bureaucrat &to_copy) : _bureaucratName(to_copy._bureaucratName), _bureaucratGrade(to_copy._bureaucratGrade)
{

};

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &original)
{
	if (this != &original)
		_bureaucratGrade = original._bureaucratGrade;
	return (*this);
};

int Bureaucrat::getBureaucratGrade() const
{
	return (_bureaucratGrade);
};

std::string Bureaucrat::getBureaucratName() const
{
	return (_bureaucratName);
};

void Bureaucrat::incrementGrade()
{
	if (_bureaucratGrade <= 1)
		throw Bureaucrat::GradeTooHighException();
	_bureaucratGrade--;
};

void Bureaucrat::decrementGrade()
{
	if (_bureaucratGrade >= 150)
		throw Bureaucrat::GradeTooLowException();
	_bureaucratGrade++;
};

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _bureaucratName << " signed " << form.getAFormName() << std::endl;
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cerr << _bureaucratName << " couldn't sign " << form.getAFormName() << " because " << e.what() << std::endl;
	}
	catch(const AForm::GradeTooHighException& e)
	{
		std::cerr << _bureaucratName << " couldn't sign " << form.getAFormName() << " because " << e.what() << std::endl;
	}
	
	

}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << _bureaucratName << " executes " << form.getAFormName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << _bureaucratName << " it's illegal to execute " << form.getAFormName() << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &to_print)
{
	out << to_print.getBureaucratName() << ", bureaucrat grade " << to_print.getBureaucratGrade();
	return (out);
}
