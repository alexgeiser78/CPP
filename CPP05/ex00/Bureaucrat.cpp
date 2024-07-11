#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("Bureaucrat"), _grade(150)
{
    std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade) : _name(name)
{
    std::cout << "Bureaucrat parameterized constructor called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException("Grade too high in constructor");
	else if (grade > 150)
		throw GradeTooLowException("Grade too low in constructor");
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
    std::cout << "Bureaucrat Copy constructor called" << std::endl;
    *this = obj;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
    std::cout << "Bureaucrat Assignation operator called" << std::endl;
    if (this != &obj)
    {
        
    }
    return (*this);
}