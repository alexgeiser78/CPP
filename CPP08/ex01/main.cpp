#include "Span.hpp"
#include <cstdlib>

int main()
{
    std::cout << "-empty container:" << std::endl;
	Span span0 = Span(0);
	std::cout << "-trying to add a number:"<< std::endl;
	try
	{
		span0.addNumber(1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "-5 elements container:" << std::endl;
    Span sp = Span(5);
    
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << "-trying to add one more element:"<< std::endl;
    try
	{
		sp.addNumber(42);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "-span(5) check:" << std::endl;
    
    try
	{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "-span(0) check:" << std::endl;
	try
	{
		std::cout << span0.shortestSpan() << std::endl;
		std::cout << span0.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "-span(10001) range check:" << std::endl;
	Span spGiant = Span(10001);
	std::vector<int> vecRange;
	std::srand(time(NULL));
	int i = 0;
	int random_int;
	
	while(i < 10001) //filling the vector with 10001 random numbers
	{
		random_int = rand() % 10001;
		vecRange.push_back(random_int);
		i++;
	}
	try
	{
		spGiant.addNumber(vecRange.begin(), vecRange.end());
		std::cout << "shortest span: " << spGiant.shortestSpan() << std::endl;
		std::cout << "longest span: " << spGiant.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
    return 0;
}