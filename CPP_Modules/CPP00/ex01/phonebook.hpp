#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

// Phonebook Class 
class Phonebook {

public: 
	Phonebook(void);
	~Phonebook(void);
	void	add();
	void	search();
	void	print(Contact contact);

private:
	Contact	_contacts[8];
	int		_index;

};

#endif