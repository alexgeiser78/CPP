#pragma once // include guard to avoid multiple header inclusion

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain*	_brain; // Pointer to Brain object
	public:
		/* Constructors & Destructors */
		Dog(void);
		Dog(std::string const &type);
		Dog(Dog const &copy);
		virtual ~Dog(void);

		/* Basic Operators */
		Dog const	&operator=(Dog const &copy);
		/* Main Member Functions */
		void	makeSound(void) const;
		virtual Brain       &getBrain(void) const;
};

class Cat: public Animal
{
	private:
		Brain*	_brain;

	public:
		/* Constructors & Destructors */
		Cat(void);
		Cat(std::string const &type);
		Cat(Cat const &copy);
		virtual ~Cat(void);

		/* Basic Operators */
		Cat const	&operator=(Cat const &copy);

		/* Getters & Setters */
		//std::string const	&getType(void) const;
		//void				setType(std::string const &type);
		virtual Brain       &getBrain(void) const;
		/* Main Member Functions */
		void	makeSound(void) const;
};