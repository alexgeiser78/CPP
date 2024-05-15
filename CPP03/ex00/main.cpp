#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap Any;
    ClapTrap Alex("Alex");
    while (Alex.get_energyPoints() > 0)
        Alex.attack("Zombie");

    

    ClapTrap Zombie("Zombie");
    while(Zombie.get_hitPoints())
    {
    Zombie.takeDamage(2);
    Zombie.beRepaired(1);
    }
    Zombie.takeDamage(1);
}