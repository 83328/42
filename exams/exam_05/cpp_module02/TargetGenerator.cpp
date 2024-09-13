#include "TargetGenerator.hpp"

TargetGenerator::~TargetGenerator()
{
	for(std::vector<ATarget*>::iterator it = _target.begin(); it != _target.end(); ++it)
		delete (*it);
	_target.clear();
}

void TargetGenerator::learnTargetType(ATarget *target)
{
	if(target)
	{
		for(std::vector<ATarget*>::iterator it = _target.begin(); it != _target.end(); ++it)
		{
			if((*it)->getType() == target->getType())
			{
				return;
			}
		}
		_target.push_back(target->clone());
	}
}

void TargetGenerator::forgetTargetType(std::string const &target)
{
	for(std::vector<ATarget*>::iterator it = _target.begin(); it != _target.end(); ++it)
	{
		if((*it)->getType() == target)
		{
			delete (*it);
			_target.erase(it);
			return;
		}
	}
}

ATarget* TargetGenerator::createTarget(std::string const &target)
{
	for(std::vector<ATarget*>::iterator it = _target.begin(); it != _target.end(); ++it)
	{
		if((*it)->getType() == target)
		{
			//(*it)->launch(target);
			return((*it)->clone());
		}
	}
	return(NULL);
}

