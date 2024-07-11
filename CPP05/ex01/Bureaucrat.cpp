#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(void): _name("Bureaucrat"), _grade(150)
{
    std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade) : _name(name)
{
    std::cout << "Bureaucrat Parameterized constructor called" << std::endl;
	if (grade < 1)
    {
            std::cout << "< 1" << std::endl;
		throw GradeTooHighException("Grade too high in constructor"); //throw, is used to signal an exception
    }
    else if (grade > 150)
    {
            std::cout << "> 150" << std::endl;
        throw GradeTooLowException("Grade too low in constructor");
    }
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj): _name(obj._name), _grade(obj._grade)
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
	if (this == &obj)
		return (*this);
	_grade = obj._grade;
    return (*this);
}
//Bureaucrat &: returns a reference to the current object
//operator= ovrerload of the assignation operator
//const Bureaucrat &obj: reference to the object. 
//_grade = obj._grade; assign the value of _grade from obj to the current object


//--------------------------------------------------------------------------------//

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

unsigned int	Bureaucrat::getGrade(void) const
{
	return(this->_grade);
}

void	Bureaucrat::incrementGrade(void)
{
    if (this->_grade <= 1)
    {
          std::cout << "grade < 1" << std::endl;
          throw GradeTooHighException("Grade too high");
    }
	this->_grade--;
}

void    Bureaucrat::decrementGrade(void)
{
    if (this->_grade >= 150)
    {
		std::cout << "grade > 150" << std::endl;
        throw GradeTooLowException("Grade too low");
    }
    this->_grade++;
}

std::ostream	&operator<<(std::ostream &output, const Bureaucrat &obj)
{
	output << obj.getName() << ", Bureaucrat grade " << obj.getGrade() << std::endl;
	return (output);
}
//output << obj.getName(): Appends the name of the Bureaucrat object to the output stream.
//obj.getGrade(): Appends the grade of the Bureaucrat object to the output stream.

//---------------------------------------------------------//

void	Bureaucrat::signForm(Form &obj) const
{
	if (obj.getSigned() == true)
		std::cout << "Form is already signed" << std::endl;
	try
	{
		obj.beSigned(*this);
		std::cout << this->_name << " signed " << obj.getName() << std::endl;
	}
	catch (std::exception &exception)
	{
		std::cerr << this->_name << " cannot sign " << obj.getName() <<
		" because " <<  exception.what() << std::endl;
	}
}