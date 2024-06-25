#include "Brain.hpp"

Brain::Brain(void) : _ideas()
{
	std::cout << "Brain created with Brain default constructor." << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain destroyed with the brain default destructor." << std::endl;
}

Brain::Brain(Brain const &copy)
{
	*this = copy;
	std::cout << "Brain copied with the brain copy constructor." << std::endl;
}

Brain const	&Brain::operator=(Brain const &copy)
{
	std::copy(copy._ideas, copy._ideas + 100, this->_ideas);
	std::cout << "Assignment operator for Brain called." << std::endl;
	return (*this);
}

std::string const	&Brain::getIdea(int const &index) const
{
	if (index >= 0 && index < 100)
		return (this->_ideas[index]);
	return (this->_ideas[0]);
}

void	Brain::setIdea(std::string const &idea, int const &index)
{
	if (index >= 0 && index < 100)
		this->_ideas[index] = idea;
}

