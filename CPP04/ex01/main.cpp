#include "Animal.hpp"
#include "Pet.hpp"
#include "Brain.hpp"
#include "Wrong.hpp"


int	main(void)
{
	const int n = 6;
	Animal *animal[n];

	for (int i = 0; i < n/2; i++)
		animal[i] = new Dog();
	for (int i = n/2; i < n; i++)
		animal[i] = new Cat();
	for (int i = 0; i < n; i++)
		animal[i]->makeSound();
	for (int i = 0; i < n; i++)
		delete animal[i];
	return (0);
}