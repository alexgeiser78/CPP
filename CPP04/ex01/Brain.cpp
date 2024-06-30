#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "idea";
}

Brain::Brain(const Brain &obj)
{
	std::cout << "Brain copy constructo called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = obj._ideas[i];
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &obj)
{
	std::cout << "Brain assignation operator called" << std::endl;
	if (this != &obj)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = obj._ideas[i];
	}
	return (*this);
}