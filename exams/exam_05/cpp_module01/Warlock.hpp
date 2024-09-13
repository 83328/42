#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
	private:
		std::string _name;
		std::string _title;
		
		Warlock() = delete;
		Warlock(Warlock const &_Warlock) = delete;
		Warlock &operator=(Warlock const &_Warlock) = delete;
		
		std::vector<ASpell*> _spell;
		
	public:
		Warlock(std::string const &name, std::string const &title);
		virtual ~Warlock();
		
		std::string const &getName() const { return _name; }
		std::string const &getTitle() const { return _title; }
		
		void setTitle(std::string const &title) { _title = title; }
		void introduce() const;
		void learnSpell(ASpell *spell);
		void forgetSpell(std::string const SpellName);
		void launchSpell(std::string const SpellName, ATarget const &target);
};
