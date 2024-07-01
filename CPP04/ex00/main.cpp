#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal	*meta = new Animal();
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();
	const WrongAnimal	*meta2 = new WrongAnimal();
	const WrongAnimal	*i2 = new WrongCat();

	std::cout << "\n" << std::endl;
    std::cout << "Dog type: " <<  j->getType() << " " << std::endl;
	std::cout << "Cat type: " << i->getType() << " " << std::endl;
	std::cout << "\n" << std::endl;

    i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
    std::cout << "\n" << std::endl;
	
    std::cout << "Wrong types" << std::endl;
	std::cout << "Cat type: " << i2->getType() << " " << std::endl;
	i2->makeSound(); //will output the Wrong animal sound!
	meta2->makeSound();
    std::cout << "\n" << std::endl;
	delete(meta);
	delete(j);
	delete(i);
	delete(i2);
	delete(meta2);
	return (0);
}

// polymorphism and inheritance
// instances are created using dynamic memory allocation (new), 
// and they are stored as pointers to their respective base classes (Animal and WrongAnimal).
// The makeSound method is called on the Cat, Dog, and Animal 
// objects. Since makeSound is a virtual method in Animal, the 
// overridden versions in Dog and Cat should be called, demonstrating 
// polymorphism.
// calling virtual methods like makeSound will execute the overridden method in the derived 
// class (Dog or Cat), demonstrating polymorphism.