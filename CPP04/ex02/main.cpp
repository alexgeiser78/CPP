#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "AAnimal.hpp"
#include "CCat.hpp"

//test virtual functions and polymorphism
void	testEval(void)
{
	std::cout << "\n" << std::endl;
	Dog basic;

	Dog tmp = basic;
}

int	main(void)
{
	const int n = 6;
	Animal *animal[n];
	// AAnimal *test[n];
	// AAnimal	prueba;
	// Animal test2;

	std::cout << "\n" << std::endl;
	for (int i = 0; i < n/2; i++)
		animal[i] = new Dog();
	std::cout << "\n" << std::endl;
	for (int i = n/2; i < n; i++)
		animal[i] = new Cat();
	std::cout << "\n" << std::endl;
	for (int i = 0; i < n; i++)
		animal[i]->makeSound();
	std::cout << "\n" << std::endl;
	for (int i = 0; i < n; i++)
		delete animal[i];
	// testEval();
	/*
	for (int i = 0; i < n; i++)
		test[i] = new CCat();
	for (int i = 0; i < n; i++)
		test[i]->makeSound();
	for (int i = 0; i < n; i++)
		delete test[i];
	return (0);*/
}