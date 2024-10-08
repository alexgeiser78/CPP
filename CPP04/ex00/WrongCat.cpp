#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat constructor called" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	this->_type = obj._type;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &obj)
{
	std::cout << "WrongCat assignation operator called" << std::endl;
	this->_type = obj._type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongCat sound: Fake Meow" << std::endl;
}

std::string	WrongCat::getType(void) const
{
	return (this->_type);
}