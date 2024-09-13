#pragma once

#include <iostream>
#include <string>

#include "ATarget.hpp"

class ATarget;

class ASpell
{
	protected:
		std::string _name;
		std::string _effects;
	
	public:
		ASpell(std::string const &name, std::string const &effects) { _name = name; _effects = effects; }
		virtual ~ASpell() { }
		
		std::string const &getName() const { return _name; }
		std::string const &getEffects() const { return _effects; }
	
		virtual ASpell* clone() const = 0;	
		void launch(ATarget const &target) const;
};
