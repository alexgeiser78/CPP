#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat bydefault;
    Bureaucrat boss("charly", 1);
    //Bureaucrat copy(boss);
    //Bureaucrat assignation = boss;
    std::cout << "\n" << std::endl;
    std::cout << "bydefault " << bydefault.getName() << std::endl;
    std::cout << "bydefault " << bydefault.getGrade() << std::endl;\
    std::cout << "boss " << boss.getName() << std::endl;
    std::cout << "boss " << boss.getGrade() << std::endl;
    std::cout << "\n" << std::endl;

	Form borringForm;
	std::cout << "\n" << std::endl;
	std::cout << "borringForm_N " << borringForm.getName() << std::endl;
	std::cout << "borringForm_GTS " << borringForm.getGradeToSign() << std::endl;
	std::cout << "borringForm_GTE " << borringForm.getGradeToExecute() << std::endl;
	
	std::cout << bydefault << "Tried to sign " << borringForm << std::endl;
	bydefault.signForm(borringForm);
	std::cout << "\n" << std::endl;
	
	try
	{
		std::cout << "high test" << std::endl;
		Form moreBorringForm("More Borring Form", 0, 10);
		std::cout << "moreBorringForm_N " << moreBorringForm.getName() << std::endl;
		std::cout << "moreBorringForm_GTS " << moreBorringForm.getGradeToSign() << std::endl;
		std::cout << "moreBorringForm_GTE " << moreBorringForm.getGradeToExecute() << std::endl;
	}
	catch (const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	std::cout << "\n" << std::endl;

	try
	{
		std::cout << "normal test" << std::endl;
		Form	evenMoreBorringForm("Even More Borring Form", 10, 10);
		std::cout << "evenMoreBorringForm_N " << evenMoreBorringForm.getName() << std::endl;
		std::cout << "evenMoreBorringForm_GTS " << evenMoreBorringForm.getGradeToSign() << std::endl;
		std::cout << "evenMoreBorringForm_GTE " << evenMoreBorringForm.getGradeToExecute() << std::endl;
		bydefault.signForm(evenMoreBorringForm);
		boss.signForm(evenMoreBorringForm);
		std::cout << evenMoreBorringForm << std::endl;
	}
	catch (const std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}





}