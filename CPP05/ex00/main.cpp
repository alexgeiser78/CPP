#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat bydefault;
    Bureaucrat boss("charly", 1);
    Bureaucrat copy(boss);
    //Bureaucrat assignation = boss;
    std::cout << "\n" << std::endl;
    std::cout << "bydefault " << bydefault.getName() << std::endl;
    std::cout << "bydefault " << bydefault.getGrade() << std::endl;\
    std::cout << "boss " << boss.getName() << std::endl;
    std::cout << "boss " << boss.getGrade() << std::endl;
    std::cout << "\n" << std::endl;

    try // try block that's gonna be checked for exceptions
	{
		std::cout << "test increment" << std::endl;
		Bureaucrat	burocrat001("Mickael", 5);
        std::cout << burocrat001 << std::endl; //insertion overload

		while (1)
		{
			burocrat001.incrementGrade();
			std::cout << burocrat001 << std::endl;
		}
	}
    /*catching by value*/
	catch (const Bureaucrat::GradeTooHighException &exception)
	{
		std::cerr << "Standard exception: " << exception.what() << std::endl;
	}
    /*catching by reference*/
    /*
	catch (const std::out_of_range &exception) //catching by reference
	{
		std::cerr << "Standard exception: " << exception.what() << std::endl;
	}*/
    std::cout << "\n" << std::endl;
    
    try
	{
		std::cout << "test decrement" << std::endl;
		Bureaucrat	burocrat002("George", 145);
        std::cout << burocrat002 << std::endl;

		while (1)
		{
			burocrat002.decrementGrade();
			std::cout << burocrat002 << std::endl;
		}
	}
    /*catching by value
	catch (const Bureaucrat::GradeTooHighException &exception)
	{
		std::cerr << "Standard exception: " << exception.what() << std::endl;
	}*/
    /*catching by reference*/
    
	catch (const std::out_of_range &exception) //catching by reference
	{
		std::cerr << "Standard exception: " << exception.what() << std::endl;
	}
    std::cout << "\n" << std::endl;

    try
	{
		std::cout << "over range" << std::endl;
		Bureaucrat	burocrat003("Mickey", 200);
        std::cout << burocrat003 << std::endl;
    }
    catch (const std::out_of_range &exception) //catching by reference
    {
        std::cerr << "Standard exception: " << exception.what() << std::endl;
    }
    std::cout << "\n" << std::endl;
    
    try
    {
        std::cout << "under range" << std::endl;
        Bureaucrat	burocrat004("Donald", 0);
        std::cout << burocrat004 << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException &exception)
	{
		std::cerr << "Standard exception: " << exception.what() << std::endl;
	}
    return 0;
}