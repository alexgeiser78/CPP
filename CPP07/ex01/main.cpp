#include <vector>
#include "iter.hpp"


void printInt(int x) 
{
    std::cout << x << std::endl;
}

void printString(std::string x) 
{
    std::cout << x << std::endl;
}

void printFloat(float x) 
{
    std::cout << x << std::endl;
}

void to_upper(std::string &str)
{
	size_t i = 0;
    while (i < str.length())
    {
        str[i] = std::toupper(str[i]);
        i++;
    }
}

void plus_five(int &i)
{
	i += 5;
}

int main() 
{
    int arr[] = {1, 2, 3, 4, 5};
    std::string arr2[] = {"a", "b", "c"};
    float arr3[] = {1.1, 2.2, 3.3};
    
    ::iter(arr, 5, printInt);
    std::cout << std::endl;
    ::iter(arr, 5, plus_five);
    ::iter(arr, 5, printInt);
    std::cout << std::endl;
    ::iter(arr2, 3, printString);
    std::cout << std::endl;
    ::iter(arr2, 3, to_upper);
    ::iter(arr2, 3, printString);
    std::cout << std::endl;
    ::iter(arr3, 3, printFloat);
    std::cout << std::endl;
    
    return 0;
}

