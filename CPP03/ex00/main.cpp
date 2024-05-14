#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap Alex("Alex");
    Alex.attack("Zombie");

    ClapTrap Zombie("Zombie");
    Zombie.takeDamage(10);
    Zombie.beRepaired(5);
    
}