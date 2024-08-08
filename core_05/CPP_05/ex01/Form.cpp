/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:53:21 by alimpens          #+#    #+#             */
/*   Updated: 2024/08/06 11:42:29 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _formSigned(false), _gradeToSign(0), _gradeToExecute(0)
{

}

Form::Form(const std::string &name, int gradeToSign) : _formName(name), _formSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(0)
{
	if (gradeToSign < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &to_copy) : _formName(to_copy._formName), _formSigned(to_copy._formSigned), _gradeToSign(to_copy._gradeToSign), _gradeToExecute(to_copy._gradeToExecute)
{

}

Form &Form::operator=(const Form &origin)
{
	if (this != &origin)
	{
		_formSigned = origin._formSigned;
	}
	return (*this);
}

Form::~Form()
{

}

const std::string &Form::getFormName() const
{
	return (_formName);
}

bool Form::getFormSigned() const
{
	return (_formSigned);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_formSigned = true;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form " << form.getFormName() << " is ";
	if (form.getFormSigned())
		out << "signed";
	else
	{
		out << "not signed";
		out << " and requires a grade of " << form.getGradeToSign() << " to sign and a grade of " << form.getGradeToExecute() << " to execute";
	}
	return (out);
}
