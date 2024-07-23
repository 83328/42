#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "contact.hpp"

# define MAX_CONTACTS 8

class Phonebook
{
	public:
		Phonebook();
		~Phonebook();
		void	addContact();
		void	searchContact();
	
	private:
		Contact	_contacts[MAX_CONTACTS];
		int		_contact_index;
};

#endif
