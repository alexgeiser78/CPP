#include "Pet.hpp"

Dog::Dog(void)
{
	std::cout << "Dog constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_type = obj._type;
	this->_brain = new Brain(*obj._brain); //creates a new brain and copies the content of the brain of the obj
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

Dog &Dog::operator=(const Dog &obj)
{
	if (this == &obj)
		return (*this);
	this->_type = obj._type;
	this->_brain = obj._brain;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof woof" << std::endl;
}

std::string	Dog::getType(void) const
{
	return (this->_type);
}
////////////////////////////////////////////////////////

Cat::Cat(void)
{
	std::cout << "Cat constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_type = obj._type;
	this->_brain = new Brain(*obj._brain);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

Cat	&Cat::operator=(const Cat &obj)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this == &obj)
		return (*this);
	this->_type = obj._type;
	this->_brain = obj._brain;
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