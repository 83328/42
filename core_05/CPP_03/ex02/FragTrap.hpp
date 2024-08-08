#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const FragTrap &FragTrap);
		FragTrap &operator=(const FragTrap &FragTrap);
		~FragTrap();

		FragTrap(const std::string &name);

		void	highFivesGuys();
};

#endif