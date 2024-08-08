/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:34:59 by alimpens          #+#    #+#             */
/*   Updated: 2024/08/02 10:57:38 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

using std::cout;
using std::endl;

int main(void)
{
	std::cout << "-----------------Animal------------------------" << std::endl;

	const Animal *Bulldog = new Dog();
	cout << endl;

	const Animal *Ragdoll = new Cat();
	cout << endl;

	cout << "-----------------Zoo------------------------" << std::endl;

	const Animal *zoo[6];

	cout << "-------------^^^ Dog ^^^--------------------" << std::endl;
	
	for (size_t i = 0; i < 3; i++)
	{
		zoo[i] = new Dog();
		cout << endl;
	}
	
	cout << "-----------------Cat------------------------" << std::endl;
	
	for (size_t i = 3; i < 6; i++) {
		zoo[i] = new Cat();
		cout << endl;
	}

	cout << "-----------------Delete Zoo ------------------------" << std::endl;
	for (size_t i = 0; i < 6; i++) {
		delete zoo[i];
		cout << endl;
	}

	cout << "----------------- Zoo Deleted ------------------------" << std::endl;

	cout << endl;

	delete Bulldog;
	delete Ragdoll;
	
	cout << endl;
	// Deep Copy Test
	cout << "-----------------Deep Copy Test------------------------" << std::endl;
	Dog basic;
	{
		Dog tmp = basic;
		// If the copy is shallow, tmp and basic will share the same Brain.
		// When tmp is destroyed at the end of this scope, it will delete the shared Brain,
		// leaving basic with a dangling pointer.
		// If the copy is deep, tmp will have its own Brain, and destroying tmp will not affect basic.
	}
	cout << "-----------------Deep Copy Test Completed------------------------" << std::endl;

	cout << endl;
	// Destruction Chaining Test
	cout << "-----------------Destruction Chaining Test------------------------" << std::endl;
	const Animal* animal = new Dog();
	delete animal;
	// If the destructor in Animal is not virtual, only the Animal destructor will be called,
	// and the Dog destructor will not be called, leading to resource leaks and undefined behavior.
	cout << "-----------------Destruction Chaining Test Completed------------------------" << std::endl;
	cout << endl;
	return 0;
}
