#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{
	private:
		void  debug();
		void  info();
		void  warning();
		void  error();
		void  nothing();
	public:
		Harl();
		void  complain(std::string level);
		~Harl();
};

#endif