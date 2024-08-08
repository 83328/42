#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

enum LogLevel
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	INVALID
};

class Harl
{
	private:
		void  debug();
		void  info();
		void  warning();
		void  error();
		void  nothing();
	LogLevel resolveLogLevel(std::string level)
	{
		if (level == "DEBUG") return DEBUG;
		if (level == "INFO") return INFO;
		if (level == "WARNING") return WARNING;
		if (level == "ERROR") return ERROR;
	}
	public:
		Harl();
		void harlFilter(std::string level);
		~Harl();
};

#endif