#include "Burocrat.hpp"

Burocrat::Burocrat(void)
{
    std::cout << "Burocrat Default constructor called" << std::endl;
}

Burocrat::Burocrat(const Burocrat &obj)
{
    std::cout << "Burocrat Copy constructor called" << std::endl;
    *this = obj;
}

Burocrat::~Burocrat(void)
{
    std::cout << "Burocrat Destructor called" << std::endl;
}

Burocrat &Burocrat::operator=(const Burocrat &obj)
{
    std::cout << "Burocrat Assignation operator called" << std::endl;
    if (this != &obj)
    {
        
    }
    return (*this);
}