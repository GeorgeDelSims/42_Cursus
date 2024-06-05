#include "FileReplacer.hpp"
#include <string>
#include <iostream>
#include <fstream>

int main(int ac, char *av[])
{
	if (ac != 4)
	{	
		std::cerr << "Please provide 3 arguments: filename(1), string(2) and string(3)" << std::endl;
		return (0);
	}
	std::string	filename = av[1];
	std::string	s1 = av[2];
	std::string	s2 = av[3];

	try 
	{
        FileReplacer		replacer(filename, s1, s2);

        replacer.replace();
        std::cout << "Replacement successful." << std::endl;
    } 
	catch (const std::exception& e) // std::exception = base class for exceptions
	{
        std::cerr << "Error: " << e.what() << std::endl; /// e.what() returns string describing error
        return (1);
    }

}