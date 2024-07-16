#include "Intern.hpp"

Intern::Intern(void)
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &obj)
{
    std::cout << "Intern copy constructor called" << std::endl;
	(void)obj;
}

Intern	&Intern::operator=(const Intern &obj)
{
    std::cout << "Intern assignation operator called" << std::endl;
	(void)obj;
	return (*this);
}

Intern::~Intern(void)
{
    std::cout << "Intern destructor called" << std::endl;
}

std::ostream	&operator<<(std::ostream &output, const Intern &obj)
{
    std::cout << "Intern print operator called" << std::endl;
	(void)obj;
	output << "intern print operator called";
	return (output);
}

AForm	*Intern::_makeShrubbery(const std::string target)
{
	ShrubberyCreationForm	*shrubbery = new ShrubberyCreationForm(target);
	return (shrubbery);
}

AForm	*Intern::_makePresidential(const std::string target)
{
	PresidentialPardonForm	*presidential = new PresidentialPardonForm(target);
	return (presidential);
}

AForm	*Intern::_makeRobotomy(const std::string target)
{
	RobotomyRequestForm	*robot = new RobotomyRequestForm(target);
	return (robot);
}

AForm	*Intern::makeForm(std::string formrequest, std::string target)
{
	std::string	names[3] = { "robotomy request", "presidential request", "shrubbery request" };
	actions[0] = &Intern::_makeRobotomy;
	actions[1] = &Intern::_makePresidential;
	actions[2] = &Intern::_makeShrubbery;
	int	i;

	i = 0;
	while (i < 3)
	{
		if (formrequest == names[i])
		{
			std::cout << "the form exists, Intern creates "<< names[i] << std::endl;
			break ;
		}
		i++;
	}
	if (i == 3)
		throw WrongValue("the form doesn't exist");
	action function = actions[i];
	AForm *result = (this->*function)(target);
	return (result);
}