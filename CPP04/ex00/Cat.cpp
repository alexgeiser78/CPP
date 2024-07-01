#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_type = obj._type;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &obj)
{
	this->_type = obj._type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meowwwwwww" << std::endl;
}

std::string	Cat::getType(void) const
{
	return (this->_type);
}