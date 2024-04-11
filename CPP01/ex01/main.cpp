#include "Zombie.hpp"

/* Creates horde of zombies named 'name' */
Zombie*	zombieHorde(int N, std::string name);

int	main(void)
{
	int	size;
    int i;

	size = 10;
    i = 0;
	Zombie *horde = zombieHorde(size, "Zombitos:"); //array of 10 zombies named
	while(i < size)
	{
		horde[i].announce(); //each zombie announces itself
		i++;
	}
	//delete [] horde;
}