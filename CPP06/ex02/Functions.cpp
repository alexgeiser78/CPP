#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base * generate(void)
{
    int i = rand() % 3;
    std::cout << "random number % 3 = " << i << std::endl;

    if (i == 0)
        return new A;
    else if (i == 1)
        return new B;
    else
        return new C;
}

//rand will generate a random number and will be different everytime I 
//load the prgm because it's related 
//to the time of the system with the function time(NULL) of the main.cpp

void identify(Base* p) //identify the dirived type of an object pointed to by the base class pointer p
{
    if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

//dynamic_cast<A*>(p) will return a pointer of type A* if the object pointed to by p is of type A, otherwise it will return a nullptr.


void identify(Base& p)
{
    try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;  //to avoid the warning of unused variable
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e) {}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e) {}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e) {}
}
//as the function identify(Base* p) but with references, need to use try-catch because 
//references can't be null and dynamic_cast will throw an exception if the cast is not possible.