/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:41:19 by alimpens          #+#    #+#             */
/*   Updated: 2024/08/07 09:48:08 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	
}

Bureaucrat::~Bureaucrat()
{
	
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : 
	_name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &to_copy) : 
	_name(to_copy._name), _grade(to_copy._grade)
{
	
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &origin)
{
	if (this != &origin)
		_grade = origin._grade;
	return (*this);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

const std::string &Bureaucrat::getName() const
{
	return (_name);
}

void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getFormName() << std::endl;
	}
	catch(const Form::GradeTooLowException &e)
	{
		std::cerr << this->getName() << " couldn't sign " << form.getFormName() << " because " << e.what() << std::endl;
	}
	catch(const Form::GradeTooHighException &e)
	{
		std::cerr << this->getName() << " couldn't sign " << form.getFormName() << " because " << e.what() << std::endl;
	}
	catch(const Form::FormAlreadySignedException &e)
	{
		std::cerr << this->getName() << " couldn't sign " << form.getFormName() << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (out);
}
