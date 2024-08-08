#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"

class Dog : public AAnimal
{
private:
    Brain *_brain;

public:
	Dog();
	Dog(const Dog &to_copy);
	Dog &operator=(const Dog &original);
	~Dog();

	void makeSound() const;
};

#endif
