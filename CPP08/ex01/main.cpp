#include "Span.hpp"

int main()
{
    std::cout << "-provided main:" << std::endl;
    Span sp = Span(5);
    
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << "-trying to add one more element:"<< std::endl;
    try
	{
		sp.addNumber(11);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

    /*
    try
	{
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}*/


    return 0;
}