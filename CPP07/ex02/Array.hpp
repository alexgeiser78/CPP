#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

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
        T				&operator[](unsigned int i); // allows non-const access to the elements of the class. It returns a reference to the element at index i.
		T const			&operator[](unsigned int i) const; // allows const acces to the elements


        // Methods
        unsigned int	size() const;

        class OutOfBounds : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#include "Array.tpp"

#endif
