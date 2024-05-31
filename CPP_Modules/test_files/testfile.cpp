#include <stdio.h>
#include <iostream>
#include "test_class.hpp"

// constructor function
Test::Test(char p1, int p2, float p3) : a1(p1), a2(p2), a3(p3)
{
	std::cout << "constructor called" << std::endl;
	
	std::cout << "this->a1 (char): " << this->a1 << std::endl;
	std::cout << "this->a2 (int): " << this->a2 << std::endl;
	std::cout << "this->a2 (float): " << this->a3 << std::endl;

	return ;
}

// destructor function
Test::~Test(void)
{
	std::cout << "destructor called" << std::endl;
	return ;
}

// member function
void	Test::member_function(void)
{
	std::cout << "member function called" << std::endl;
	return ;
}

int main()
{
	Test	instance('a', 42, 4.2f);

	// instance.attribute = 42;
	// std::cout << "instance.attribute:" << instance.attribute << std::endl; 

	instance.member_function();

	return (0);
}


/*
int	main (void)
{
	char buffer[512];

	std::cout << "Hello World" << std::endl;
	std::cout << "input a word: ";
	std::cin >> buffer;
	std::cout << "you entered : [" << buffer << "]" << std::endl;
	
	return (0);
}
*/