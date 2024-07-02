#include "Cat.hpp"

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

Cat &Cat::operator=(const Cat &obj)
{
    std::cout << "Cat assignation operator called" << std::endl;
    if (this != &obj)  // Correct condition check for self-assignment
    {
        this->_type = obj._type;
        delete this->_brain;  // Free the existing memory
        this->_brain = new Brain(*obj._brain); // Deep copy of Brain
    }
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