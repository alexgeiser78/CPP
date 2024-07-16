#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) :
AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
    std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target
+ "_shrubbery", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm Parameterized constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj)
: AForm(obj), _target(obj._target)
{
    std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
	return ;
}


ShrubberyCreationForm &ShrubberyCreationForm::operator=(const
ShrubberyCreationForm &obj)
{
	AForm::operator=(obj);
	return (*this);
}

bool	ShrubberyCreationForm::checkRequirement(const Bureaucrat &executor) const
{
	if (executor.getGrade() > 145 || getGradeToExecute() > 137)
		return (0);
	return (1);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!checkRequirement(executor))
		throw AForm::GradeTooLowException("Not enough grade to execute form");
	std::ofstream	outfile((_target + "_shrubbery").c_str()); //outfile((_target + "_shrubbery").c_str()): This attempts to open a file for writing. The filename is constructed by appending "_shrubbery" to the _target member variable of the ShrubberyCreationForm object. The c_str() function is called to convert the resulting std::string to a C-style string (i.e., a null-terminated character array).
	if (!outfile)
		std::cerr << _target << " could not be opened" << std::endl;
	outfile << "       _-_" << std::endl;
	outfile << "    /~~   ~~\\" << std::endl;
	outfile << " /~~         ~~\\" << std::endl;
	outfile << "{               }" << std::endl;
	outfile << " \\  _-     -_  /" << std::endl;
	outfile << "   ~  \\\\ //  ~" << std::endl;
	outfile << "_- -   | | _- _" << std::endl;
	outfile << "  _ -  | |   -_" << std::endl;
	outfile << "      // \\\\" << std::endl;
	outfile.close();
}