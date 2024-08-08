#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(const WrongCat &to_copy);
        WrongCat &operator=(const WrongCat &original);
        ~WrongCat();

        void makeSound() const;
};

#endif
