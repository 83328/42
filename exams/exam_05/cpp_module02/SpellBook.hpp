#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "ASpell.hpp"


class SpellBook
{
	private:
		SpellBook(SpellBook const &src) = delete;
		SpellBook &operator=(SpellBook const &src) = delete;
		
		std::vector<ASpell*> _spell;
		
	public:
		SpellBook() { }
		~SpellBook();

		void learnSpell(ASpell*);
		void forgetSpell(std::string const &);
		ASpell* createSpell(std::string const &);
};
