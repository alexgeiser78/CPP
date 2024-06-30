#pragma once // include guard to avoid multiple header inclusion

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog &obj);
		~Dog(void);
		Dog &operator=(const Dog &obj);

		std::string	getType(void) const;
		void		makeSound(void) const;
	private:
		Brain *_brain;
};

class	Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat &obj);
		~Cat(void);
		Cat	&operator=(const Cat &obj);

		std::string	getType(void) const;
		void		makeSound(void) const;
	private:
		Brain	*_brain;
};