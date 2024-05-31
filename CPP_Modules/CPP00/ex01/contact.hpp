#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm> 
#include <cctype>

// Contact Class 
class Contact {

public:
	Contact(void);
	~Contact(void);
	void	set_firstname(std::string str);
	void	set_lastname(std::string str);
	void	set_nickname(std::string str);
	void	set_number(std::string str);
	void	set_secret(std::string str);
	std::string		get_firstname(void) const;
	std::string		get_lastname(void) const;
	std::string		get_nickname(void) const;
	std::string		get_number(void) const;
	std::string		get_secret(void) const;

private:

	std::string _firstname;
	std::string _lastname;
	std::string _nickname;
	std::string _number;
	std::string _secret;
};

#endif