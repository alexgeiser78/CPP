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