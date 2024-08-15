#include "Array.hpp"

#include <iostream>



int main()
{
Array<int> emptyArray;
std::cout << "emptyArray size = " << emptyArray.size() << std::endl;

Array<int> intArray(4);
std::cout << "intArray size = " << intArray.size() << std::endl;

int *a = new int();
std::cout << "*a = " << *a << std::endl;
delete a;

int *b = new int[4]();
std::cout << "b[0] = " << b[0] << std::endl;
std::cout << "b[1] = " << b[1] << std::endl;
std::cout << "b[2] = " << b[2] << std::endl;
std::cout << "b[3] = " << b[3] << std::endl;
delete [] b;

return 0;
}