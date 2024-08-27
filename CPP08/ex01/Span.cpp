#include "Span.hpp"

// Constructors

Span::Span() : _n(0)
{
    std::cout << "Default constructor called with _n initalised to 0" << std::endl;
}

Span::Span(unsigned int N) : _n(N)
{
    std::cout << "Parametric constructor called with _n initalised to " << N << std::endl;
}

Span::Span(const Span &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Span &Span::operator=(Span const &other)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &other)
    {
        this->_n = other._n;
    }
    return (*this);
}

Span::~Span()
{
    std::cout << "Destructor called" << std::endl;
}

// Members

void Span::addNumber(int n)
{
    if (this->_n == 0)
        throw FullContainerException();
    std::cout << "Adding number " << n << std::endl;
    this->_n--;
    std::cout << "Remaining slots: " << this->_n << std::endl;
    this->_vec.push_back(n);
}

// Exceptions

const char *Span::FullContainerException::what() const throw()
{
	return ("Container is full");
}

const char *Span::NotEnoughNumbersException::what() const throw()
{
	return ("Not enough numbers in container");
}
