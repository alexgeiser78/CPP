#include "Pet.hpp"

Dog::Dog(void): Animal("Dog")
{
    std::cout << "Dog from Animal " << Animal::_type << " created with default constructor." << std::endl;
}

Dog::Dog(std::string const &type): Animal(type)
{
    std::cout << "Dog from Animal " << Animal::_type << " created." << std::endl;
}

Dog::Dog(Dog const &copy): Animal(copy)
{
    *this = copy;
    std::cout << "Dog from Animal " << Animal::_type << " copied." << std::endl;
}

Dog::~Dog(void)
{
    std::cout << "Dog from Animal " << Animal::_type << " destroyed." << std::endl;
}

Dog const	&Dog::operator=(Dog const &copy)
{
    std::cout << "Assignment operator for Dog from Animal " << Animal::_type << " called." << std::endl;
    Animal::operator=(copy);
    return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog From Animal " << Animal::_type << " goes WafWaf!" << std::endl;
}

////////////////////////////////////////////////////////

Cat::Cat(void) : Animal("Cat") {
    std::cout << "Cat created with default constructor." << std::endl;
}

Cat::Cat(std::string const &type) : Animal(type) {
    std::cout << "Cat created with type " << type << "." << std::endl;
}

Cat::Cat(Cat const &copy) : Animal(copy) {
    *this = copy;
    std::cout << "Cat copied." << std::endl;
}

Cat::~Cat(void) {
    std::cout << "Cat destroyed." << std::endl;
}

Cat const &Cat::operator=(Cat const &copy) {
    std::cout << "Assignment operator for Cat called." << std::endl;
    if (this != &copy) {
        Animal::operator=(copy);
    }
    return *this;
}

void Cat::makeSound(void) const {
    std::cout << "Cat From Animal goes Maow!" << std::endl;
}

