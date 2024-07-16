#include "AForm.hpp"

AForm::AForm(void) : _name("Default"), _signed(false), _gradeToSign(150),
_gradeToExecute(150)
{
	std::cout << "AForm Default constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) :
_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "AForm Parameterized constructor called" << std::endl;
	if (gradeToSign < 1)
		throw (GradeTooHighException("Grade too high constructor"));
	else if (gradeToSign > 150)
		throw (GradeTooLowException("Grade too low constructor"));
	if (gradeToExecute < 1)
		throw (GradeTooHighException("Grade too high constructor"));
	else if (gradeToExecute > 150)
		throw (GradeTooLowException("Grade too low constructor"));
}

AForm::AForm(AForm const &obj) : _name(obj._name), _signed(obj._signed),
_gradeToSign(obj._gradeToSign), _gradeToExecute(obj._gradeToExecute)
{
	std::cout << "Copy constructor called" << std::endl;
}

AForm::~AForm(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

AForm	&AForm::operator=(AForm const &obj)
{
	if (this == &obj)
		return (*this);
	this->_signed = obj._signed;
	return (*this);
}

std::string	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getSigned(void) const
{
	return (this->_signed);
}

int		AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int		AForm::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

//If the grade of the bureaucrat is high enough to sign the form, it sets signed to true
void AForm::beSigned(const Bureaucrat &obj)
{
	if (this->_gradeToSign < static_cast<int>(obj.getGrade()))
		throw (GradeTooLowException("Grade too low to sign"));
	this->_signed = true;
}

void	AForm::createDerived(const Bureaucrat &executor)
{
	if (checkRequirement(executor))
	{
			execute(executor);
	}
	else
		std::cerr << "Not able to create the derived object" << std::endl;
}

std::ostream &operator<<(std::ostream &output, const AForm &obj)
{
	output << "AForm " << obj.getName() << " is ";
	if (obj.getSigned())
		output << "signed";
	else
		output << "not signed";
	output << " and requires grade " << obj.getGradeToSign() << " to sign and "
	<< obj.getGradeToExecute() << " to execute" << std::endl;
	return (output);
}