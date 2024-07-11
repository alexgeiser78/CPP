#include "Form.hpp"

Form::Form(void) : _name("Default"), _signed(false), _gradeToSign(150),
_gradeToExecute(150)
{
    std::cout << "Form Default constructor called" << std::endl;
}

Form::Form(const std::string name, unsigned int gradeToSign, unsigned int gradeToExecute) :
_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Form Parameterized constructor called" << std::endl;
    if (gradeToSign < 1)
		throw (GradeTooHighException("Grade too high constructor"));
	else if (gradeToSign > 150)
		throw (GradeTooLowException("Grade too low constructor"));
	if (gradeToExecute < 1)
		throw (GradeTooHighException("Grade too high constructor"));
	else if (gradeToExecute > 150)
		throw (GradeTooLowException("Grade too low constructor"));
}

Form::Form(Form const &obj) : _name(obj._name), _signed(obj._signed),
_gradeToSign(obj._gradeToSign), _gradeToExecute(obj._gradeToExecute)
{
    std::cout << "Form Copy constructor called" << std::endl;
    *this = obj;
}

Form::~Form(void)
{
	std::cout << "Form " << this->_name << " destroyed" << std::endl;
}

Form &Form::operator=(Form const &obj)
{
	if (this == &obj)
		return (*this);
	this->_signed = obj._signed;
	return (*this);
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getSigned(void) const
{
	return (this->_signed);
}

unsigned int		Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

unsigned int		Form::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

void Form::beSigned(const Bureaucrat &obj)
{
	if (this->_gradeToSign < (obj.getGrade()))
		throw (GradeTooLowException("Grade too low to sign"));
	this->_signed = true;
}

std::ostream &operator<<(std::ostream &output, const Form &obj)
{
	output << "Form " << obj.getName() << " which is ";
	if (obj.getSigned())
		output << "already signed";
	else
		output << "not signed";
	output << " and requires grade " << obj.getGradeToSign() << " to sign and "
	<< obj.getGradeToExecute() << " to execute" << std::endl;
	return (output);
}

