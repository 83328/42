#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const ScavTrap &ScavTrap);
		ScavTrap &operator=(const ScavTrap &ScavTrap);
		~ScavTrap();

		ScavTrap(const std::string &name);

		void	guardGate();
};

# endif