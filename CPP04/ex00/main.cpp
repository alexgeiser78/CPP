#include "Animal.hpp"
#include "Pet.hpp"
#include "Wrong.hpp"


int main() 
{
    const Animal *meta = new Animal("mammal");
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    const WrongAnimal *k = new WrongCat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << k->getType() << " " << std::endl;

    i->makeSound();
    j->makeSound();
    k->makeSound();
    
    delete meta;
    delete i;
    delete j;   
    delete k;
    
    return 0;
}