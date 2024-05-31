#include "phonebook.hpp"

int	main(void)
{
	Phonebook		_phonebook;
	std::string		str;
	
	while (str != "EXIT")
	{
		std::cout << "Enter a command : ";
		std::getline(std::cin, str);
		if (str == "ADD")
			_phonebook.add();
		else if (str == "SEARCH")
			_phonebook.search();
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
	}
	return (0);
}
