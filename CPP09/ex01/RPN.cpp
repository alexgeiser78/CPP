#include "RPN.hpp"

// constructors

RPN::RPN()
{
    std::cout << "RPN default constructor called" << std::endl;
}

RPN::RPN(const std::string &str)
{

}

RPN::RPN(const RPN &other)
{
    std::cout << "RPN copy constructor called" << std::endl;
    if (this != &other)
        *this = other;
}

RPN &RPN::operator=(RPN const &other)
{
    std::cout << "RPN operator= called" << std::endl;
    if (this != &other)
    {
        // _quotes = other._quotes;
    }
    return (*this);
}

RPN::~RPN()
{
    std::cout << "RPN destructor called" << std::endl;
}

// Getters

int RPN::getResult() const
{

}

// member functions

int RPN::plus(int a, int b)
{
    
}

