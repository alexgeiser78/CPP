#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack();
	MutantStack(MutantStack const &other);
	MutantStack &operator=(MutantStack const &other);
	~MutantStack();

	typedef typename std::stack<T>::container_type::iterator iterator; //creates an alias named "iterator" for the iterator type of the container used by std::stack<T> (std::deque<T>::iterator)
	iterator begin(); //read and write access to the elements of the stack
	iterator end();

	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	const_iterator begin() const; //read-only access to the elements of the stack
	const_iterator end() const;

	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	reverse_iterator rbegin(); //read and write access to the elements of the stack in reverse order
	reverse_iterator rend();

	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
	const_reverse_iterator rbegin() const; //read-only access to the elements of the stack in reverse order
	const_reverse_iterator rend() const;
};

# include "MutantStack.tpp"

#endif