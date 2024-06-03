#include "Zombie.hpp"

int	main()
{
	Zombie	*z = newZombie("Jean-Michel");
	z->announce();
	randomChump("Patrick");
	return (0);
}
