#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB 
{
    public:
        HumanB(const std::string  name);
        ~HumanB();

        // Add methods here 
        void        setWeapon(Weapon &weapon);
        Weapon      *getWeapon() const;
        void        attack() const;

    private:
        // Add member variables here
        std::string     _name;
        Weapon          *_weapon;
};

#endif // HumanB_HPP
