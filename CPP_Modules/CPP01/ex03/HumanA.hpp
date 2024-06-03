#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA 
{
    public:
        HumanA(const std::string name, Weapon& weapon);
        ~HumanA();

        // Add methods here
        void        setWeapon(Weapon& weapon);
        Weapon&     getWeapon() const;
        void        attack() const;

    private:
        // Add member variables here
        std::string     _name;
        Weapon&         _weapon;
};

#endif // HumanA_HPP
