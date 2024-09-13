#pragma once

#include <iostream>
#include <string>

#include "ASpell.hpp"

class ASpell;

class ATarget
{
	protected:
		std::string _type;
	
	public:
		ATarget(std::string const &type) { _type = type; }
		virtual ~ATarget() { }
		
		std::string const &getType() const { return _type; }
	
		virtual ATarget* clone() const = 0;	
		void getHitBySpell(ASpell const &spell) const;
};
