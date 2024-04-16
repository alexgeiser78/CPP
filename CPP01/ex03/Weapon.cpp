#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type)
{
    std::cout << "Weapon object " << _type << " constructed" << std::endl;
}

Weapon::~Weapon(void)
{
    std::cout << "Weapon object " << _type << " destroyed" << std::endl;
}

const std::string&	Weapon::getType(void)
{
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}