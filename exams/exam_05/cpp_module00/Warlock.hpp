#pragma once

#include <iostream>
#include <string>

class Warlock
{
	private:
		std::string _name;
		std::string _title;
		
		Warlock() = delete;
		Warlock(Warlock const &_Warlock) = delete;
		Warlock &operator=(Warlock const &_Warlock) = delete;
	
	public:
		Warlock(std::string const &name, std::string const &title);
		~Warlock();
		
		std::string const &getName() const { return _name; }
		std::string const &getTitle() const { return _title; }
		
		void setTitle(std::string const &title) { _title = title; }
		void introduce() const;
};
