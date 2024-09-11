#include "RPN.hpp"

// constructors

RPN::RPN()
{
    //std::cout << "RPN default constructor called" << std::endl;
}

RPN::RPN(const std::string &str)
{
    //std::cout << "RPN parametrised constructor called" << std::endl;
    std::stringstream stringStream(str);
    std::string element;
    int  number;

    while (std::getline(stringStream, element, ' ')) // split string by space
    {
        if ((element.length() == 1 && isdigit(element[0])) || (element.length() == 2 && element[0] == '-' && isdigit(element[1]))) // check if element is a number or a negative number
        {
			std::stringstream(element) >> number; // convert string to int
			stack.push(number); // push number to stack
		}
        else if (element == "+")
            calcStack(&RPN::plus);
        else if (element == "-")
            calcStack(&RPN::minus);
        else if (element == "*")
            calcStack(&RPN::multiply);
        else if (element == "/")
            calcStack(&RPN::divide);
        else
            throw RPN::invalidArgument("Invalid argument: " + element);
    }

}

RPN::RPN(const RPN &other)
{
    //std::cout << "RPN copy constructor called" << std::endl;
    if (this != &other)
        *this = other;
}

RPN &RPN::operator=(RPN const &other)
{
    //std::cout << "RPN operator= called" << std::endl;
    if (this != &other)
        stack = other.stack;
    return (*this);
}

RPN::~RPN()
{
    //std::cout << "RPN destructor called" << std::endl;
}

// Getters

int RPN::getResult() const
{
    if (stack.empty())
		throw RPN::emptyStack("Empty stack");
	else if (stack.size() > 1)
		throw RPN::invalidArgument("Invalid argument"); // stack not well unstacked or too many numbers
	return (stack.top());
}

// member functions

int RPN::plus(int a, int b)
{
    return (b + a); // b + a because we are using a stack and the first element is the last to be added
}

int RPN::minus(int a, int b)
{
    return (b - a);
}

int RPN::multiply(int a, int b)
{
    return (b * a);
}

int RPN::divide(int a, int b)
{
    if (a == 0)
		throw RPN::divisionByZero("Division by zero");
	return (b / a);
}

void RPN::calcStack(int (RPN::*f)(int, int)) // pointer to member function with argument of 2 int returning an int
{
    if (stack.size() < 2)
        throw RPN::missingNumbers("Missing numbers");
    
    int a;
    int b;
    a = stack.top(); //get top element of stack
    stack.pop(); // remove top element of stack
    b = stack.top(); // get new top element of stack
    stack.pop(); // remove top element of stack
    stack.push((this->*f)(a, b)); //memeber function is called on the actual object (this) on the 2 numbers and the result is pushed to the stack
}   

// exceptions

RPN::divisionByZero::divisionByZero(const std::string& msg) : std::runtime_error(msg)
{
    //std::cout << "divisionByZero constructor called" << std::endl;
}

RPN::emptyStack::emptyStack(const std::string& msg) : std::runtime_error(msg)
{
    //std::cout << "emptyStack constructor called" << std::endl;
}

RPN::invalidArgument::invalidArgument(const std::string& msg) : std::runtime_error(msg)
{
    //std::cout << "invalidArgument constructor called" << std::endl;
}

RPN::missingNumbers::missingNumbers(const std::string& msg) : std::runtime_error(msg)
{
    //std::cout << "missingNumbers constructor called" << std::endl;
}

