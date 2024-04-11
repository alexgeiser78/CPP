#include "Zombie.hpp"

Zombie::Zombie(std::string name) //parameterized constructor
{
	this->_name = name;
	std::cout << "Zombie object " << this->_name << " created" << std::endl;
}

Zombie::Zombie(void)    //default constructor
{
	this->_name = "(null)";
	std::cout << "Zombie object " << this->_name << " created" << std::endl;
}

Zombie::~Zombie() //destructor
{
	std::cout << "Zombie object " << this->_name << " destroyed" << std::endl;
}

void	Zombie::announce()
{
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}