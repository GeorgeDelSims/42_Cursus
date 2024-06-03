#include <iostream>
#include <string>
#include "Example.hpp"

void	byPtr(std::string *str)
{
	*str += " is bollocks";
}

void	byConstPtr(std::string const *str)
{
	std::cout << *str << std::endl;
}

void	byRef(std::string& str)
{
	str += " and other stuff";
}

void	byConstRef(std::string const& str)
{
	std::cout << str << std::endl;
}

int main()
{
	std::string	str = "scotch and eggs";

	std::cout << str << std::endl;
	byPtr(&str);
	byConstPtr(&str);

	str = "eggs and bacon";
	std::cout << str << std::endl;
	byRef(str);
	byConstRef(str);
	return (0);
}