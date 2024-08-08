#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	protected:
		std::string	_name;
		int			_hitpoints;
		int			_energyPoints;
		int			_attackDamage;

	public:
		ClapTrap();
		ClapTrap(const ClapTrap &_ClapTrap);
		ClapTrap &operator=(const ClapTrap &_ClapTrap);
		~ClapTrap();

		ClapTrap(const std::string &name);
		std::string	getName() const;

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

};

#endif