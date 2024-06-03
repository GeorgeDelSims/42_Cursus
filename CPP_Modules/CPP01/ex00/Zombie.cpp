#include "Zombie.hpp"

Zombie::Zombie(std::string name) 
{
    this->_name = name;
    std::cout << this->_name << " created" << std::endl;
}

Zombie::~Zombie() 
{
    std::cout << this->_name << " destroyed" << std::endl;
}

// Add methods implementation here
void    Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
