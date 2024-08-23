#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) : _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day.\n"; 
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!\n";   
	/* for (std::map <std::string, ASpell*>::iterator it = _SpellBook.begin(); it != _SpellBook.end(); ++it)
		delete (it->second);
	_SpellBook.clear(); */
}

void Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!\n"; 
}

void Warlock::learnSpell(ASpell *spell)
{
	/* if (spell)
		if (_SpellBook.find(spell->getName()) == _SpellBook.end())
			_SpellBook[spell->getName()] = spell->clone(); */
	_SpellBook.learnSpell(spell);
}

void Warlock::forgetSpell(std::string const SpellName)
{
	_SpellBook.forgetSpell(SpellName);
	
	/* if (_SpellBook.find(SpellName) != _SpellBook.end())
		_SpellBook.erase(_SpellBook.find(SpellName)); */
}

void Warlock::launchSpell(std::string const SpellName, ATarget const &target)
{
	if (_SpellBook.createSpell(SpellName))
		_SpellBook.createSpell(SpellName)->launch(target);
	/* if (_SpellBook.find(SpellName) != _SpellBook.end())
		_SpellBook[SpellName] -> launch(target); */
}
