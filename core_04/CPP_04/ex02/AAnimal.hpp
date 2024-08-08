#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class AAnimal
{
	protected:
		std::string _type;

	public:
		AAnimal();
		AAnimal(const AAnimal &to_copy);
		AAnimal &operator=(const AAnimal &original);
		virtual ~AAnimal();
		virtual void makeSound() const = 0;

		std::string getType() const;
		void setType(std::string type);
};

#endif
