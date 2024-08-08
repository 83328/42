#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"


class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &to_copy);
		Cat &operator=(const Cat &original);
		~Cat();

		void makeSound() const;
};

#endif
