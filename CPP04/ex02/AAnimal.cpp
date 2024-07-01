#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
	std::cout << "AAnimal constructor called" << std::endl;
	this->_type = "AAnimal";
}

AAnimal::AAnimal(const AAnimal &obj)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	this->_type = obj._type;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &obj)
{
	std::cout << "AAnimal assignation operator called" << std::endl;
	if (this == &obj)
		return (*this);
	*this = obj;
	return (*this);
}

std::string	AAnimal::getType(void) const
{
	return (this->_type);
}