#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int	main(void)
{
	Intern	random;
	AForm	*presidential;
	AForm	*unknown;
	Bureaucrat anotherBureaucrat("anotherBureaucrat", 1);
	std::cout << "---------------------" << std::endl;	

	presidential = random.makeForm("presidential request", "randomIntern's ");
	std::cout << "---------------------" << std::endl;

	try
	{
		unknown = random.makeForm("unknown", "nobody");// should throw an exception
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "---------------------" << std::endl;
	 
	anotherBureaucrat.signAForm(*presidential);
	anotherBureaucrat.executeForm(*presidential);
	std::cout << "---------------------" << std::endl;

	Intern random2;
	AForm *rrf2 = random2.makeForm("robotomy request", "random_president");
	Bureaucrat anotherBureaucrat2("anotherBureaucrat2", 1);
	std::cout << "---------------------" << std::endl;

	anotherBureaucrat2.signAForm(*rrf2);
	anotherBureaucrat2.executeForm(*rrf2);
	std::cout << "---------------------" << std::endl;

	try
	{
		Intern random3;
		AForm *fail = random3.makeForm("fail", "random_fail");
		Bureaucrat anotherBureaucrat3("anotherBureaucrat3", 1);

		anotherBureaucrat3.signAForm(*fail);
		anotherBureaucrat3.executeForm(*fail);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	Intern random4;
	AForm *shrubbery = random4.makeForm("shrubbery request", "random_people");
	Bureaucrat anotherBureaucrat4("anotherBureaucrat4", 1);
	anotherBureaucrat4.executeForm(*shrubbery);
	std::cout << "---------------------" << std::endl;
	
	delete (presidential);
	delete (rrf2);
	delete (shrubbery);
	return (0);
}