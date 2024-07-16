#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm",
72, 45), _target("default")
{
    std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target +
"_robotomy", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm Parameterized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) :
AForm(obj), _target(obj._target)
{
    std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm
&obj)
{
	AForm::operator=(obj);
	return (*this);
}

bool	RobotomyRequestForm::checkRequirement(const Bureaucrat &executor) const
{
	if (executor.getGrade() > 72 || getGradeToExecute() > 45)
	{
		std::cerr << "Robotomy failed" << std::endl;
		return (0);
	}
	return (1);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!checkRequirement(executor))
		throw AForm::GradeTooLowException("Grade or executor is too low");
	std::cout << "!!Drilling noise!!" << std::endl;
	if (std::rand() % 2 == 0) // 50% chance
    {
        std::cout << _target << " has been robotomized successfully" << std::endl;
    }
    else
    {
        std::cout << "Robotomy of " << _target << " failed" << std::endl;
    }
}