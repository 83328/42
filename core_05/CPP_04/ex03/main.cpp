/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:23:47 by alimpens          #+#    #+#             */
/*   Updated: 2024/08/02 17:05:30 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#include <iostream>

int main()
{
	// Original test
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	// Test 1: Equipping more than the allowed number of Materia
	std::cout << "\nTest 1: Equipping more than the allowed number of Materia\n";
	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	me = new Character("me");

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice"); // This should not be equipped
	me->equip(tmp);
	delete tmp; // Delete the last allocated but not equipped Materia

	for (int i = 0; i < 5; ++i)
	{
		me->use(i, *me); // Only the first 4 should work
	}

	delete me;
	delete src;

	// Test 2: Using an unequipped Materia
	std::cout << "\nTest 2: Using an unequipped Materia\n";
	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	me = new Character("me");

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	me->use(2, *me); // This should not do anything as slot 2 is empty

	delete me;
	delete src;

	return 0;
}
