#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog &obj);
		~Dog(void);
		Dog &operator=(const Dog &obj);

		std::string	getType(void) const;
		void		makeSound(void) const;
};
#endif