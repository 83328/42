#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
    private:
        std::string _type;
    
    public:
        Cure();
        Cure(Cure const & src);
        Cure& operator=(Cure const &original);
        ~Cure();

        AMateria* clone() const;
        std::string const & getType() const;
        void use(ICharacter& target);
};

#endif
