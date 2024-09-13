#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "ATarget.hpp"


class TargetGenerator
{
	private:
		TargetGenerator(TargetGenerator const &src) = delete;
		TargetGenerator &operator=(TargetGenerator const &src) = delete;
		
		std::vector<ATarget*> _target;
		
	public:
		TargetGenerator() { }
		~TargetGenerator();
		
		void learnTargetType(ATarget*);
		void forgetTargetType(std::string const &);
		ATarget* createTarget(std::string const &);
};
