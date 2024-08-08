/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:58:15 by alimpens          #+#    #+#             */
/*   Updated: 2024/08/06 14:40:42 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _aFormSigned(false), _gradeToSign(0), _gradeToExec(0)
{
	
};

AForm::AForm(const std::string &name, int gradeToSign) : _aFormName(name), _aFormSigned(false), _gradeToSign(gradeToSign), _gradeToExec(0)
{
	if (gradeToSign < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExec) : _aFormName(name), _aFormSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &to_copy) : _aFormName(to_copy._aFormName), _aFormSigned(to_copy._aFormSigned), _gradeToSign(to_copy._gradeToSign), _gradeToExec(to_copy._gradeToExec)
{
	
};

AForm &AForm::operator=(const AForm &original)
{
	if (this != &original)
		_aFormSigned = original._aFormSigned;
	return (*this);
}

AForm::~AForm()
{
	
};

std::string AForm::getAFormName() const
{
	return (_aFormName);
}

bool AForm::isAFormSigned() const
{
	return (_aFormSigned);
}

int AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int AForm::getGradeToExec() const
{
	return (_gradeToExec);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getBureaucratGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_aFormSigned = true;
}

//unsure about the part beneath
std::ostream &operator<<(std::ostream &out, const AForm &aForm)
{
	out << "Form " << aForm.getAFormName() << " is ";
	if (!aForm.isAFormSigned())
		out << "not ";
	out << "signed, requires grade " << aForm.getGradeToSign() << " to sign and grade " << aForm.getGradeToExec() << " to execute";
	return (out);
}
