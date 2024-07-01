#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

//test virtual functions and polymorphism
static void	testEval(void)
{
	std::cout << "\n" << std::endl;
	Dog basic; // creates a Dog object named basic.

	Dog tmp = basic; // creates another Dog object named tmp and copies the state of basic into it. This tests the copy constructor of the Dog class.
}

int	main(void)
{
	const int n = 6;
	Animal *animal[n]; // array of pointers to animals

	for (int i = 0; i < n/2; i++)
		animal[i] = new Dog(); // 3 dogs objects
	std::cout << "\n" << std::endl;
	for (int i = n/2; i < n; i++)
		animal[i] = new Cat(); // 3 cats objects
	std::cout << "\n" << std::endl;
	for (int i = 0; i < n; i++)
		animal[i]->makeSound();
	std::cout << "\n" << std::endl;
	for (int i = 0; i < n; i++)
		delete animal[i];
	std::cout << "eval test" << std::endl;
	testEval();
	return (0);
}