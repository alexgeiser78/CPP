#include "CCat.hpp"

CCat::CCat(void)
{
	std::cout << "CCat constructor called" << std::endl;
	this->_type = "CCat";
	this->_brain = new Brain();
}

CCat::CCat(const CCat &obj) : AAnimal(obj)
{
	std::cout << "CCat copy constructor called" << std::endl;
	this->_type = obj._type;
	this->_brain = new Brain(*obj._brain);
}

CCat::~CCat(void)
{
	std::cout << "CCat destructor called" << std::endl;
	delete this->_brain;
}

CCat	&CCat::operator=(const CCat &obj)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this == &obj)
    {
        this->_type = obj._type;
        delete this->_brain;  // Free the existing memory
        this->_brain = new Brain(*obj._brain); // Deep copy of Brain
    }
	return (*this);
}

void	CCat::makeSound(void) const
{
	std::cout << "Meowwwwwww" << std::endl;
}

std::string	CCat::getType(void) const
{
	return (this->_type);
}