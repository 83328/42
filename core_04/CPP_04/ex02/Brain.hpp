#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string _ideas[100];

	public:
		Brain();
		Brain(const Brain &to_copy);
		Brain &operator=(const Brain &original);
		~Brain();
};

#endif