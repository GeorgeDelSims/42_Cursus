#include "Zombie.hpp"

int	main(int ac, char *av[])
{
	if (ac < 3)
	{	
		std::cout << "You forgot to say how many zombies you want. Execute with number of zombies + name as arguments" << std::endl;
		return (0);
	}
	int		N = std::stoi(av[1]);
	Zombie	*horde = zombieHorde(N, av[2]);

	for (int i = 0; i < N; i++)
		horde[i].announce();
	
	delete[] horde;
	return (0);
}