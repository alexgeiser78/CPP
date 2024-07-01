#ifndef CCAT_HPP
# define CCAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class	CCat : public AAnimal
{
	public:
		CCat(void);
		CCat(const CCat &obj);
		~CCat(void);
		CCat	&operator=(const CCat &obj);

		std::string	getType(void) const;
		void		makeSound(void) const;
	private:
		Brain	*_brain;
};
#endif