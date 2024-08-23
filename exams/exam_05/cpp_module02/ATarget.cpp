#include "ATarget.hpp"

ATarget::ATarget(std::string type) : _type(type)
{

}

std::string ATarget::getType () const
{
	return (_type);
}

void ATarget::getHitBySpell(ASpell const &spell) const
{
	std::cout << _type << " has been " << spell.getEffects() << "!\n";
}
