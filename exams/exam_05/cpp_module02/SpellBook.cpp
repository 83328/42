#include "SpellBook.hpp"

SpellBook::~SpellBook()
{
	for(std::vector<ASpell*>::iterator it = _spell.begin(); it != _spell.end(); ++it)
		delete (*it);
	_spell.clear();
}

void SpellBook::learnSpell(ASpell *spell)
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

void SpellBook::forgetSpell(std::string const &SpellName)
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

//void SpellBook::launchSpell(std::string const SpellName, ATarget const &target)
ASpell* SpellBook::createSpell(std::string const &SpellName)
{
	for(std::vector<ASpell*>::iterator it = _spell.begin(); it != _spell.end(); ++it)
	{
		if((*it)->getName() == SpellName)
		{
			//(*it)->launch(target);
			return((*it)->clone());
		}
	}
	return(NULL);
}

