#include "phonebook.hpp"

// Function that shortens the string to the max width given
static std::string truncate(const std::string &str, const int width)
{
	if ((int)str.length() > width)
		return (str.substr(0, width - 1)) + ".";
	return (str);
}

void	Phonebook::search(void)
{
	const int	width = 10;
	int			i;

	std::cout << " | " << std::setw(width) << std::right << "Index" << " | "
					<< std::setw(width) << std::right << "First Name" << " | "
					<< std::setw(width) << std::right << "Last Name" << " | "
					<< std::setw(width) << std::right << "Nickame" << " | "
					<< std::setw(width) << std::right << "Number" << " | "
					<< std::setw(width) << std::right << "Secret" <<  " | " << std::endl;
	std::cout << std::string((width + 6) * 5, '-') << std::endl;
	
	for (i = 0; i < 8; i++)
	{
		std::cout << " | " << std::setw(width) << std::right << i << " | "
					<< std::setw(width) << std::right << truncate(this->_contacts[i].get_firstname(), width) << " | "
					<< std::setw(width) << std::right << truncate(this->_contacts[i].get_lastname(), width) << " | "
					<< std::setw(width) << std::right << truncate(this->_contacts[i].get_nickname(), width) << " | "
					<< std::setw(width) << std::right << truncate(this->_contacts[i].get_number(), width) << " | "
					<< std::setw(width) << std::right << truncate(this->_contacts[i].get_secret(), width) <<  " | " << std::endl;
	}
	return ;
}
