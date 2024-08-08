/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:34:59 by alimpens          #+#    #+#             */
/*   Updated: 2024/08/02 12:01:46 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {
    // Test AAnimal class (should not compile)
    // AAnimal animal; // Uncommenting this line should give a compile error

    // Test polymorphism with AAnimal pointers
    AAnimal* animals[2];
    animals[0] = new Cat();
    animals[1] = new Dog();

    for (int i = 0; i < 2; ++i) {
        std::cout << animals[i]->getType() << " says: ";
        animals[i]->makeSound();
    }

    for (int i = 0; i < 2; ++i) {
        delete animals[i];
    }

    return 0;
}
