#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap Any;
    ScavTrap other;
    ScavTrap Alex("Alex");
    while (Alex.get_energyPoints() > 0)
        Alex.attack("Zombie");

    

    ScavTrap Zombie("Zombie");
    while(Zombie.get_hitPoints())
    {
    Zombie.takeDamage(20);
    Zombie.beRepaired(10);
    }
    Zombie.takeDamage(1);
    Zombie.guardGate();
}