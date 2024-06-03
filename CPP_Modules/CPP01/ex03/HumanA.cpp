#include "HumanA.hpp"

HumanA::HumanA(const std::string  name, Weapon& weapon) : _name(name), _weapon(weapon) {}

HumanA::~HumanA() {}

void    HumanA::setWeapon(Weapon& weapon)
{
    this->_weapon = weapon;
}

Weapon&  HumanA::getWeapon() const
{
    return (this->_weapon);
}

void    HumanA::attack() const
{
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}