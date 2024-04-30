#include "Fixed.hpp"
#include <iostream>

int main( void ) 
{
    Fixed a; //default constructor
    Fixed b( a ); //copy constructor (a) is passed as parameter to the copy constructor, b is created as a deep copy of a
    Fixed c; //default constructor
    c = b; //value of b is assigned to c
    //std::cout << a.getRawBits() << std::endl;
    //std::cout << b.getRawBits() << std::endl;
    //std::cout << c.getRawBits() << std::endl;
    return 0;
}