#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <cctype>
# include <cstdlib>

class Contact
{
public:
	Contact();
	~Contact();
	void saveContact(const std::string& firstname, const std::string& lastname, const std::string& nickname, const std::string& phone_number, const std::string& darkest_secret);
	void printDetails() const;
	std::string getFirstName() const { return _firstname; }
	std::string getLastName() const { return _lastname; }
	std::string getNickName() const { return _nickname; }

private:
	std::string _firstname;
	std::string _lastname;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;
};

#endif
