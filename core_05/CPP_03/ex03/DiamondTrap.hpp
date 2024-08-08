#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public virtual ClapTrap, public ScavTrap, public FragTrap
{
public:
	DiamondTrap(const std::string &name);
	void whoAmI();

	int getHitPoints() const;
	int getEnergyPoints() const;
	int getAttackDamage() const;

private:
	std::string _name;
};

/* 
Virtual inheritance: In the DiamondTrap class both ScavTrap 
and FragTrap inherit from ClapTrap. This prevents ClapTrap from being 
created by both ScavTrap and FragTrap.
*/

#endif