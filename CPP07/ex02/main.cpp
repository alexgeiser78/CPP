#include <iostream>
#include "Array.hpp"



int main()
{
    std::cout << "-Empty Array Creation" << std::endl;
    Array<int> emptyArray;
    std::cout << "emptyArray size = " << emptyArray.size() << std::endl;
    try 
    {
		std::cout << "emptyArray[5]= " << emptyArray[5] << std::endl;
	}
    catch (std::exception &e) 
    {
		std::cout << e.what() << std::endl;
	}
    std::cout << std::endl;

    std::cout << "-Array of 4 creation, initialised to 0" << std::endl;
    Array<int> intArray(4);
    std::cout << "intArray size = " << intArray.size() << std::endl;
    try 
    {
		std::cout << "intArray[3] = " << intArray[3] << std::endl;
	}
    catch (std::exception &e) 
    {
		std::cout << e.what() << std::endl;
	}
    std::cout << std::endl;

    std::cout << "-Array of 5 creation, initialised to i" << std::endl;
    Array<int> otherIntArray(5);
	int i = 0;
	while (i < 5) 
    {
		otherIntArray[i] = i;
		i++;
	}
	std::cout << "otherIntArray size: " << otherIntArray.size() << std::endl;
	std::cout << "otherIntArray init: " << std::endl;
	i = 0;
	while (i < 5) 
    {
		std::cout << otherIntArray[i] << " " << std::endl;
		i++;
	}
	std::cout << std::endl;

    std::cout << "-Copy constructor using int array init to 0" << std::endl;
    Array<int> intArrayCopy(intArray);
    std::cout << "intArrayCopy size: " << intArrayCopy.size() << std::endl;
    std::cout << "intArrayCopy init: " << std::endl;
    i = 0;
    while (i < 4) 
    {
        std::cout << intArrayCopy[i] << " " << std::endl;
        i++;
    }
    std::cout << std::endl;

    std::cout << "-Copy constructor using int array" << std::endl;
    Array<int> otherIntArrayCopy(otherIntArray);
    std::cout << "intArrayCopy size: " << otherIntArrayCopy.size() << std::endl;
    std::cout << "intArrayCopy init: " << std::endl;
    i = 0;
    while (i < 5) 
    {
        std::cout << otherIntArrayCopy[i] << " " << std::endl;
        i++;
    }
    std::cout << std::endl;

    std::cout << "-Const array" << std::endl;
    const Array<int> constIntArray(intArray);
    std::cout << "constIntArray size: " << constIntArray.size() << std::endl;
    i = 0;
    std::cout << "constIntArray init: " << std::endl;
	while (i < 4) 
    {
		std::cout << constIntArray[i] << " " << std::endl;
		i++;
	}
	std::cout << std::endl;

    std::cout << "-Dynamic Memory" << std::endl;
    int *a = new int(); // new int allocates memory for an int, () initializes it to 0, a is a pointer to the memory location
    std::cout << "*a = " << *a << std::endl;
    *a = 42;
    std::cout << "*a = " << *a << std::endl;
    delete a;
    std::cout << std::endl;

    std::cout << "-Dynamic Array Memory" << std::endl;
    int *b = new int[4]();
    std::cout << "b[0] = " << b[0] << std::endl;
    std::cout << "b[1] = " << b[1] << std::endl;
    std::cout << "b[2] = " << b[2] << std::endl;
    std::cout << "b[3] = " << b[3] << std::endl;
    std::cout << "modifying b[0] to 42" << std::endl;
    b[0] = 42;
    std::cout << "b[0] = " << b[0] << std::endl;
    delete [] b;
    std::cout << std::endl;

    return 0;
}