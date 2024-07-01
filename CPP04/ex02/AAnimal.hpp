#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal
{
	public:
		AAnimal(void);
		AAnimal(const AAnimal &obj);
		virtual ~AAnimal(void);
		AAnimal &operator=(const AAnimal &obj);

		std::string		getType(void) const;
		virtual void	makeSound(void) const = 0; // pure virtual function
	protected:
		std::string _type;
};
#endif

// AAnimmal is an abstract class because it has a pure virtual function
// this means that it cannot be instantiated
// any derived class must provide an implementation for this function.