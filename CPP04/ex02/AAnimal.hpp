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
		virtual void	makeSound(void) const = 0;
	protected:
		std::string _type;
};
#endif