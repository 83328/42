/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:59:26 by alimpens          #+#    #+#             */
/*   Updated: 2024/08/06 14:52:29 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
    
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
    this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &to_copy)
{
    *this = to_copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &original)
{
    if (this != &original)
        _target = original._target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!this->isAFormSigned())
        throw AForm::FormNotSignedException();
    if (executor.getBureaucratGrade() > this->getGradeToExec())
        throw AForm::GradeTooLowException();
    std::srand(std::time(0));
    if (std::rand() % 2)
        std::cout << this->_target << " has been robotomized." << std::endl;
    else
        std::cout << this->_target << " robotomization failed." << std::endl;
}
