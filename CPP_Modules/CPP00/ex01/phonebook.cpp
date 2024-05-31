#include "phonebook.hpp"

Phonebook::Phonebook(void)
{
	this->_index = 0;
	std::cout << "Welcome to shitty phonebook, feel free to add your shitty contacts" << std::endl;
	return ;
}

Phonebook::~Phonebook(void)
{
	std::cout << "Arrivederci" << std::endl;
	return ;
}
