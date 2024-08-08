/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:34:59 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/31 14:41:37 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "****************************** Animal ******************************" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete j;
	delete i;
	delete meta;

	std::cout << std::endl;
	std::cout << "****************************** Wrong Animal ******************************" << std::endl;
	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongCat* i2 = new WrongCat();
	
	std::cout << i2->getType() << " " << std::endl;

	i2->makeSound(); //will output the cat sound!

	delete meta2;
	delete i2;

	return (0);

}
