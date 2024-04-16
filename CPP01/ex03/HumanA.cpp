#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon)
{
	std::cout << "HumanA " << name << " created with ";
	std::cout << weapon.getType() << std::endl;
}  //constructor initializes name and weapon

HumanA::~HumanA(void)
{
	std::cout << "HumanA " << this->_name << " destroyed" << std::endl;
} //destructor 

void	HumanA::attack(void) //attack function related to HumanA
{
	std::cout << this->_name << " attacks with his " << \
		this->_weapon.getType() << std::endl;
}
