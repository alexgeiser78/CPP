#include "FragTrap.hpp"

int main(void)
{
    ClapTrap Any;
    FragTrap Other;
    FragTrap Alex("Alex");
    Alex.highFivesGuys();

    while (Alex.get_energyPoints() > 0)
        Alex.attack("Zombie");

    FragTrap Zombie("Zombie");
    while(Zombie.get_hitPoints())
    {
    Zombie.takeDamage(20);
    Zombie.beRepaired(10);
    }
    Zombie.takeDamage(1);
    Zombie.highFivesGuys();
}