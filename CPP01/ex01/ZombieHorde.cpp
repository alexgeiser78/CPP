#include "Zombie.hpp"

//mandatory function

Zombie*	zombieHorde(int N, std::string name)
{
    int i;

    i = 0;
	Zombie *horde = new Zombie[N];
    while(i < N)
    {
        horde[i].setName(name);
        i++;
    }
	return (horde); //return pointer to array of N zombies
}