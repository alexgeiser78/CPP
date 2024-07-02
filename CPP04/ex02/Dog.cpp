#include "Dog.hpp"

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
	std::cout << "Dog assignment operator called" << std::endl;
	if (this == &obj)
		{
        this->_type = obj._type;
        delete this->_brain;  // Free the existing memory
        this->_brain = new Brain(*obj._brain); // Deep copy of Brain
    	}
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