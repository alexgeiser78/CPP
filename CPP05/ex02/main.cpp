#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat test1("test1", 5);
	Bureaucrat test2("test2", 146);
	Bureaucrat test3("test3", 25);
	Bureaucrat test4("test4", 46);
	Bureaucrat test5("test5", 125);
	Bureaucrat test6("test6", 1);

	std::cout << test1 << std::endl;
	std::cout << test2 << std::endl;
	std::cout << test3 << std::endl;
	std::cout << test4 << std::endl;
	std::cout << test5 << std::endl;
	std::cout << test6 << std::endl;

	std::cout << "---------------------" << std::endl;
	test1.executeForm(ShrubberyCreationForm("form1"));
	test2.executeForm(ShrubberyCreationForm("form2"));
	std::cout << "---------------------" << std::endl;
	test3.executeForm(RobotomyRequestForm("form3"));
	test4.executeForm(RobotomyRequestForm("form4"));
	std::cout << "---------------------" << std::endl;
	test5.executeForm(PresidentialPardonForm("form5"));
	test6.executeForm(PresidentialPardonForm("form6"));

	std::cout << "---------------------" << std::endl;
	ShrubberyCreationForm	form7("form1");
	RobotomyRequestForm		form8("form2");

	std::cout << form7 << std::endl;
	std::cout << form8 << std::endl;
	test1.signAForm(form7);
	test2.signAForm(form8);

	std::cout << "---------------------" << std::endl;
	test1.executeForm(form7);
	test2.executeForm(form8);
	return (0);
}