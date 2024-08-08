#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"

class Cat : public AAnimal
{
	private:
		Brain *_brain;

	public:
		Cat();
		Cat(const Cat &to_copy);
		Cat &operator=(const Cat &original);
		~Cat();

		void makeSound() const;
};

#endif
