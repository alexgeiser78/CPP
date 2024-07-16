#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) :
AForm("PresidentialPardonForm", 25, 5), _target("default")
{
    std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
AForm(target + "presidential", 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm Parameterized constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm
&obj) : AForm(obj), _target(obj._target)
{
    std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}
PresidentialPardonForm	&PresidentialPardonForm::operator=(const
PresidentialPardonForm &obj)
{
	AForm::operator=(obj);
	return (*this);
}

bool	PresidentialPardonForm::checkRequirement(const Bureaucrat &executor) const
{
	if (executor.getGrade() > 25 || getGradeToExecute() > 5)
		return (0);
	return (1);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!checkRequirement(executor))
		throw AForm::GradeTooLowException("Grade too low to execute");
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}