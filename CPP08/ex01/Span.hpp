#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
    private:
        unsigned int _n;
        std::vector<int> _vec;
    public:
        //constructors
        Span();
        Span(unsigned int n);
        Span(const Span &other);
        Span &operator=(Span const &other);
        ~Span();

        //members
        void addNumber(int n);
        void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan();
        int longestSpan();

        //exceptions
    class FullContainerException : public std::exception
	    {
		public:
			virtual const char *what() const throw();
	    };

	class NotEnoughNumbersException : public std::exception
	    {
		public:
			virtual const char *what() const throw();
	    };

};

#endif