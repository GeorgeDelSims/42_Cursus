#include "phonebook.hpp"

static bool is_not_space(unsigned char ch) 
{
    return !std::isspace(ch);
}

// Function to trim whitespace from both ends of a string
static std::string trim(const std::string& str) 
{
    std::string result = str;

    // Remove leading whitespace
    result.erase(result.begin(), std::find_if(result.begin(), result.end(), is_not_space));
    // Remove trailing whitespace
    result.erase(std::find_if(result.rbegin(), result.rend(), is_not_space).base(), result.end());

    return result;
}

// Function to add a contact to the phonebook
void	Phonebook::add(void)
{
	std::string	str;

	str = "";
	if (_index > 7)
		std::cout << "Warning: Overwriting info about " << this->_contacts[this->_index % 8].get_firstname() << std::endl;
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Input first name: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].set_firstname(trim(str)); 
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Input " << this->_contacts[this->_index].get_firstname() << "'s last name: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].set_lastname(trim(str)); 
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Input " << this->_contacts[this->_index].get_firstname() << "'s nickname: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].set_nickname(trim(str)); 
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Input " << this->_contacts[this->_index].get_firstname() << "'s number: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].set_number(trim(str)); 
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Input " << this->_contacts[this->_index].get_firstname() << "'s darkest secret: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].set_secret(trim(str)); 
	}
	str = "";
	this->_index++;
}
