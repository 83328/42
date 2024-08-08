#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	private:
		std::string _type;
	
	public:
		Ice();
		Ice(Ice const & src);
		Ice& operator=(Ice const &original);
		~Ice();

		AMateria* clone() const;
		std::string const & getType() const;
		void use(ICharacter& target);
};

#endif