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
	for(std::vector<ASpell*>::iterator it = _spell.begin(); it != _spell.end(); ++it)
		delete (*it);
	_spell.clear();
}

void Warlock::introduce() const
{
	std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!\n";
}

void Warlock::learnSpell(ASpell *spell)
{
	if(spell)
	{
		for(std::vector<ASpell*>::iterator it = _spell.begin(); it != _spell.end(); ++it)
		{
			if((*it)->getName() == spell->getName())
			{
				return;
			}
		}
		_spell.push_back(spell->clone());
	}
}

void Warlock::forgetSpell(std::string const SpellName)
{
	for(std::vector<ASpell*>::iterator it = _spell.begin(); it != _spell.end(); ++it)
	{
		if((*it)->getName() == SpellName)
		{
			delete (*it);
			_spell.erase(it);
			return;
		}
	}
}

void Warlock::launchSpell(std::string const SpellName, ATarget const &target)
{
	for(std::vector<ASpell*>::iterator it = _spell.begin(); it != _spell.end(); ++it)
	{
		if((*it)->getName() == SpellName)
		{
			(*it)->launch(target);
			return;
		}
	}
}

