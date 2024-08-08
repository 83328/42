#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class Animal
{
	protected:
		std::string _type;

	public:
		Animal();
		Animal(const Animal &to_copy);
		Animal& operator=(const Animal &original);
		virtual ~Animal();
		//virtual indicates polymorphism here - we can override the function later

		virtual void makeSound() const;
		std::string getType() const;
		void setType(std::string type);
};

#endif
