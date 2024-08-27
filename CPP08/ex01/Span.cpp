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

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) // 2 iterators pointing to the beginning and the end of the range
{
    if (_vec.size() + std::distance(begin, end) > _n) //_vec.size = numb of elem already in the container, std::distance(begin, end) = numb of elem in the range, if the sum of the 2 is greater than the total number of slots, throw exception
        throw FullContainerException();
    _vec.insert(_vec.end(), begin, end); //inserting the range of numbers at the end of the container
}

int Span::shortestSpan()
{
    unsigned long i = 1;

    if (this->_vec.size() < 2) // if there are less than 2 numbers in the container, span cannot be calculated
        throw NotEnoughNumbersException();
    std::cout << "Calculating shortest span" << std::endl;
    std::cout << "Copy of the container" << std::endl;
    std::vector<int> tmp = _vec; // copy of the container
    std::cout << "Sorting the copy in ascending order" << std::endl;
    std::sort(tmp.begin(), tmp.end()); // sorting the copy in ascending order
    
    /*
    unsigned long j = 0;
    while(j < tmp.size()) // displaying the copy
    {
        std::cout << "element: " << tmp[j] << std::endl;
        ++j;
    }*/
    
    int min = tmp[1] - tmp[0]; //initial min span before iterating
    
    int span;
    while(i < tmp.size() -1) // iterating through the copy to find the shortest span
    {
        span = tmp[i + 1] - tmp[i];
        if (span < min)
            min = span;
        ++i;
    }
    std::cout << "Shortest span: " << std::endl;
    return (min);
}

int Span::longestSpan()
{
    if (this->_vec.size() < 2)
        throw NotEnoughNumbersException();
    std::cout << "Calculating longest span" << std::endl;
    std::cout << "Copy of the container" << std::endl;
    std::vector<int> tmp = _vec;
    std::cout << "Sorting the copy in ascending order" << std::endl;
    std::sort(tmp.begin(), tmp.end());
    int longest = tmp[tmp.size() - 1] - tmp[0]; // initial longest span before iterating
    std::cout << "Difference between " << tmp[0] << " and " << tmp[tmp.size() - 1] << ": " << longest << std::endl;
    std::cout << "Longest span: " << std::endl;
    return (longest); // differnce between the smallest and the largest number
}

// Exceptions

const char *Span::FullContainerException::what() const throw()
{
	return ("No space left in container");
}

const char *Span::NotEnoughNumbersException::what() const throw()
{
	return ("Not enough numbers in container to calculate span");
}
