#include "HumanB.hpp"

HumanB::HumanB(const std::string  name) 
{
    this->_name = name;
    this->_weapon = NULL;
}

HumanB::~HumanB() {}

Weapon  *HumanB::getWeapon() const
{
    return (this->_weapon);
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}

void    HumanB::attack() const
{
    if (this->_weapon != NULL)
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
    else 
        std::cout << this->_name << " has no weapon to attack with!" << std::endl;
}
