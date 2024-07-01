#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

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
#endif

// Brain *_brain; is a pointer to a Brain object. Each Cat object has its own Brain object, demonstrating composition. This allows each Cat to have its own separate brain with its own state.

