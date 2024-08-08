/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:40:50 by alimpens          #+#    #+#             */
/*   Updated: 2024/08/07 09:48:11 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
1. Define an exception class (inherits from std::exception)
2. Throw an exception (use the throw keyword)
3. Catch an exception  (use the try/catch block to handle the exception)
*/

#include "Bureaucrat.hpp"
#include "Form.hpp"

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    // Test 1: Bureaucrat signing a form
    // *******************************
    std::cout << "Test 1: Bureaucrat signing a form\n";
    std::cout << "*******************************\n";
    try
    {
        Bureaucrat working("Mac", 1);
        Form form("Form1", 100);
        working.signForm(form);

        std::cout << form.getFormName() << " signed: " << form.getFormSigned() << std::endl;
    }
    catch(const Form::GradeTooHighException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const Form::GradeTooLowException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n";

    // Test 2: Bureaucrat with grade too high
    // **************************************
    std::cout << "Test 2: Bureaucrat with grade too high\n";
    std::cout << "**************************************\n";
    try
    {
        Bureaucrat tooHigh("Dennis", 0);
    }
    catch(const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }

    std::cout << "\n";

    // Test 3: Bureaucrat with grade too low
    // *************************************
    std::cout << "Test 3: Bureaucrat with grade too low\n";
    std::cout << "*************************************\n";
    try
    {
        Bureaucrat tooLow("Frank", 151);
    }
    catch(const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }

    std::cout << "\n";

    // Test 4: Form with grade too high
    // ********************************
    std::cout << "Test 4: Form with grade too high\n";
    std::cout << "********************************\n";
    try
    {
        Form formTooHigh("Form2", 0);
    }
    catch(const Form::GradeTooHighException &e)
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }

    std::cout << "\n";

    // Test 5: Form with grade too low
    // *******************************
    std::cout << "Test 5: Form with grade too low\n";
    std::cout << "*******************************\n";
    try
    {
        Form formTooLow("Form3", 151);
    }
    catch(const Form::GradeTooLowException &e)
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }

    std::cout << "\n";

    // Test 6: Bureaucrat trying to sign a form with insufficient grade
    // ***************************************************************
    std::cout << "Test 6: Bureaucrat trying to sign a form with insufficient grade\n";
    std::cout << "***************************************************************\n";
    try
    {
        Bureaucrat lowRank("Charlie", 150);
        Form form("Form4", 100);
        lowRank.signForm(form);
    }
    catch(const Form::GradeTooLowException &e)
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }
    catch(const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }

    return 0;
}

/* int main()
{
	try
	{
		Bureaucrat working("John", 1);
		Form form("Form1", 100);
		working.signForm(form);

		std::cout << form.getFormName() << " signed: " << form.getFormSigned() << std::endl;
	}
	catch(const Form::GradeTooHighException &e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
} */