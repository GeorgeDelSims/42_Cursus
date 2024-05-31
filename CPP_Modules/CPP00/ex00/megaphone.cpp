#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

unsigned char to_upper(unsigned char c) 
{
    return std::toupper(c);
}


int	main (int ac, char *av[])
{
	int				i;
	std::string		concatenated_str;

	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (i = 1; i < ac; ++i)
			concatenated_str += av[i];
	}
	std::transform(concatenated_str.begin(),concatenated_str.end(), concatenated_str.begin(), to_upper);

    std::cout << concatenated_str << std::endl;

	return (0);
}
