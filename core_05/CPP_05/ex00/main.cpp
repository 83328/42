/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:40:50 by alimpens          #+#    #+#             */
/*   Updated: 2024/08/07 09:48:18 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
1. Define an exception class (inherits from std::exception)
2. Throw an exception (use the throw keyword)
3. Catch an exception  (use the try/catch block to handle the exception)
*/

#include "Bureaucrat.hpp"

/* int main()
{
	try
	{
		Bureaucrat b("Bob", 1);
		std::cout << b;
		b.incrementGrade();
		std::cout << b;
		b.incrementGrade();
		std::cout << b;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
} */

int main()
{
	try
	{
		std::cout << std::endl;
		std::cout << "*************************************************************" << std::endl;
		std::cout << "Test case 1: Create a Bureaucrat with the highest grade (1) and increment it" << std::endl;
		std::cout << "*************************************************************" << std::endl;
		Bureaucrat b1("Dennis", 1);
		std::cout << b1;
		b1.incrementGrade(); // This should throw an exception
		std::cout << b1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl;
		std::cout << "*************************************************************" << std::endl;
		std::cout << "Test case 2: Create a Bureaucrat with a middle grade (50) and increment it" << std::endl;
		std::cout << "*************************************************************" << std::endl;
		Bureaucrat b2("Frank", 50);
		std::cout << b2;
		b2.incrementGrade(); // This should succeed
		std::cout << b2;
		b2.incrementGrade(); // This should succeed
		std::cout << b2;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl;
		std::cout << "*************************************************************" << std::endl;
		std::cout << "Test case 3: Create a Bureaucrat with the lowest grade (150) and decrement it" << std::endl;
		std::cout << "*************************************************************" << std::endl;
		Bureaucrat b3("Charlie", 150);
		std::cout << b3;
		b3.decrementGrade(); // This should throw an exception
		std::cout << b3;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl;
		std::cout << "*************************************************************" << std::endl;
		std::cout << "Test case 4: Create a Bureaucrat with an invalid high grade (0)" << std::endl;
		std::cout << "*************************************************************" << std::endl;
		Bureaucrat b4("Mac", 0); // This should throw an exception
		std::cout << b4;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl;
		std::cout << "*************************************************************" << std::endl;
		std::cout << "Test case 5: Create a Bureaucrat with an invalid low grade (151)" << std::endl;
		std::cout << "*************************************************************" << std::endl;
		Bureaucrat b5("Dee", 151); // This should throw an exception
		std::cout << b5;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}