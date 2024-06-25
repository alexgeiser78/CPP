#include "Pet.hpp"

Dog::Dog(void): Animal("Dog"), _brain(new Brain())
{
    std::cout << "Dog from Animal " << Animal::_type << " created with default constructor." << std::endl;
}

Dog::Dog(std::string const &type): Animal(type)
{
    std::cout << "Dog from Animal " << Animal::_type << " created." << std::endl;
}

Dog::Dog(Dog const &copy): Animal(copy), _brain(new Brain(*copy._brain))
{
    *this = copy;
    std::cout << "Dog from Animal " << Animal::_type << " copied." << std::endl;
}

Dog::~Dog(void)
{
    delete _brain;
    std::cout << "Dog from Animal " << Animal::_type << " destroyed." << std::endl;
}

Dog const	&Dog::operator=(Dog const &copy)
{
    std::cout << "Assignment operator for Dog from Animal " << Animal::_type << " called." << std::endl;
    if (this != &copy) {
        Animal::operator=(copy);
        delete _brain;  // Libérer l'ancien cerveau
        _brain = new Brain(*copy._brain);  // Copier le cerveau
    }
    return (*this);
}

Brain &Dog::getBrain() const 
{
    return *_brain;
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog From Animal " << Animal::_type << " goes WafWaf!" << std::endl;
}

////////////////////////////////////////////////////////

Cat::Cat(void) : Animal("Cat"), _brain(new Brain())
{
    std::cout << "Cat created with default cat constructor." << std::endl;
}

Cat::Cat(std::string const &type) : Animal(type) {
    std::cout << "Cat created with type " << type << "." << std::endl;
}

Cat::Cat(Cat const &copy) : Animal(copy), _brain(new Brain(*copy._brain)) 
{
    *this = copy;
    std::cout << "Cat copied." << std::endl;
}

Cat::~Cat(void) 
{
    delete _brain;
    std::cout << "Cat destroyed." << std::endl;
}

Cat const &Cat::operator=(Cat const &copy) {
    std::cout << "Assignment operator for Cat called." << std::endl;
    if (this != &copy) 
    {
        Animal::operator=(copy);
        delete _brain;
        _brain = new Brain(*copy._brain);
    }
    return *this;
}

void Cat::makeSound(void) const 
{
    std::cout << "Cat From Animal goes Maow!" << std::endl;
}

Brain &Cat::getBrain() const 
{
    return *_brain;
}

