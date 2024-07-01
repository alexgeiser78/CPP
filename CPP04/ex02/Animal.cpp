#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal constructor called" << std::endl;
	this->_type = "Animal";
}

Animal::Animal(const Animal &obj)
{
	std::cout << "Animal copy constructor called" << std::endl;
	this->_type = obj._type;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &obj)
{
	std::cout << "Animal assignation operator called" << std::endl;
	if (this == &obj)
		return (*this);
	this->_type = obj._type;
	return (*this);
}

void Animal::makeSound(void) const
{
	std::cout << "Animal is making noise" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}