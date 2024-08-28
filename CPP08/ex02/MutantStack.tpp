#include "MutantStack.hpp"

//constructor

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
    std::cout << "MutantStack constructor called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &other) : std::stack<T>(other)
{
    std::cout << "MutantStack copy constructor called" << std::endl;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &other)
{
	if (this != &other)
		std::stack<T>::operator=(other); // calls the operator= of the parent class (std::stack)
	std::cout << "MutantStack operator= called" << std::endl;
    return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack()
{
    std::cout << "MutantStack destructor called" << std::endl;
}

//iterator finctions

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() //provides an iterator to the first element of the stack
{
	return (std::stack<T>::c.begin()); //c is a protected member of std::stack that is a container (std::deque) that holds the elements of the stack
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (std::stack<T>::c.end());
}

//const_iterator functions

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return (std::stack<T>::c.end());
}

//reverse_iterator functions

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return (std::stack<T>::c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return (std::stack<T>::c.rend());
}

//const_reverse_iterator functions

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
	return (std::stack<T>::c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
	return (std::stack<T>::c.rend());
}




