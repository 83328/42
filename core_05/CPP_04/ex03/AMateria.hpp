#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>

class ICharacter; // to avoid circular dependencies

class AMateria
{
	protected:
		std::string _type;
		
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(AMateria const & src);
		AMateria& operator=(AMateria const &original);
		virtual ~AMateria();

		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
