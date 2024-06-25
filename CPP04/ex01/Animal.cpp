#include "Animal.hpp"

Animal::Animal(void): _type("Any animal")
{
	std::cout << "Animal: " << this->_type << " created with Animal default constructor." << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal " << this->_type << " destroyed with animal destructor." << std::endl;
}

Animal::Animal(std::string const &type): _type(type)
{
	std::cout << "Animal created with type " << this->_type << std::endl;
}

Animal::Animal(Animal const &copy)
{
	*this = copy;
	std::cout << "Animal " << this->_type << " copied with Animal copy constructor." << std::endl;
}

Animal const	&Animal::operator=(Animal const &copy)
{
	std::cout << "Assignment operator for Animal " << this->_type << " called." << std::endl;
	this->_type = copy.getType();
	return (*this);
}

std::string const	&Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::setType(const std::string &type)
{
	this->_type = type;
}
/*
void	Animal::makeSound(void) const
{
	std::cout << "Any animal " << this->_type << " made a sound!" << std::endl;
}

Brain &Animal::getBrain(void) const 
{
	std::cout << "Animal " << this->_type << " has no brain." << std::endl;
	return (new Brain());
}
*/
