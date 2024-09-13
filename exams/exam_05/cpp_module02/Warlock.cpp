#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title)
{
	this->_name = name;
	this->_title = title;
	std::cout << this->_name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
	std::cout << this->_name << ": My job here is done!\n";
}

void Warlock::introduce() const
{
	std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!\n";
}

void Warlock::learnSpell(ASpell *spell)
{
	_SpellBook.learnSpell(spell);
}

void Warlock::forgetSpell(std::string const SpellName)
{
	_SpellBook.forgetSpell(SpellName);
}

void Warlock::launchSpell(std::string const SpellName, ATarget const &target)
{
	if(_SpellBook.createSpell(SpellName))
		_SpellBook.createSpell(SpellName)->launch(target);
}

