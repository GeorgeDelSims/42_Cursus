#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie 
{
    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        void    announce(void);
        void    setName(std::string name);

    private:
        std::string     _name;
};

// Returns pointer to Zombie object allocated on the stack with new
Zombie	*newZombie(std::string name);
// Creates new Zombie stored on the heap, which announces itself
// Zombie is automatically destroyed at the end of the function scope
void	randomChump(std::string name);
// allocates N Zombie objects, initialises zombies with name
// returns pointer to the first zombie in the horde
Zombie  *zombieHorde(int N, std::string name);

#endif
