#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T> //class template Array that contains elements of type T
class Array
{
    private:
        T* _arr;
        unsigned int _size;
    public:
		// Constructors
		Array();
		Array(unsigned int n);
		Array(Array const &copy);
		~Array();

        // Operators
		Array			&operator=(Array const &copy);

        // Methods
        unsigned int	size() const;
};
#include "Array.tpp"

#endif
