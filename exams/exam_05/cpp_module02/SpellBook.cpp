#include "SpellBook.hpp"

SpellBook::~SpellBook()
{
	for (std::vector<ASpell*>::iterator it = _spell.begin(); it != _spell.end(); ++it)
		delete (*it);
	_spell.clear();
}

void SpellBook::learnSpell(ASpell *spell)
{
	if (spell) {
		for (std::vector<ASpell*>::iterator it = _spell.begin(); it != _spell.end(); ++it) {
			if ((*it)->getName() == spell->getName())
				return;
		}
		_spell.push_back(spell->clone());
	}
}

void SpellBook::forgetSpell(std::string const &SpellName)
{

	for (std::vector<ASpell*>::iterator it = _spell.begin(); it != _spell.end(); ++it) {
			if ((*it)->getName() == SpellName) {
				delete (*it);
				_spell.erase(it);
				return;
			}
		}
}
//SpellBook is same like Warlock.cpp from previous ex.
ASpell* SpellBook::createSpell(std::string const &SpellName)
{
	for (std::vector<ASpell*>::iterator it = _spell.begin(); it != _spell.end(); ++it) {
			if ((*it)->getName() == SpellName) {
				return ((*it)->clone());
			}
	}
	return (NULL);
	// ASpell* tmp = NULL;
	// if (_SpellBook.find(SpellName) != _SpellBook.end())
	//     tmp = _SpellBook[SpellName];
	// return (tmp);
}
