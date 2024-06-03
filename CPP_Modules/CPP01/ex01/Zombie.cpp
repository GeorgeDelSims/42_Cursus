#include "Zombie.hpp"

Zombie::Zombie(std::string name) 
{
    this->_name = name;
    std::cout << "Zombie object " << this->_name << " created" << std::endl;
}

Zombie::Zombie(void)
{
    this->_name = "(null)";
    std::cout << "Zombie object " << this->_name << " created" << std::endl;
}

Zombie::~Zombie() 
{
    std::cout << "Zombie object " << this->_name << " destroyed" << std::endl;
}

// Add methods implementation here
void    Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string name)
{
    this->_name = name;
    std::cout << "name set for " << this->_name << std::endl;
}
