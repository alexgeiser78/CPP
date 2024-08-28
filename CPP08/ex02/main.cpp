#include "MutantStack.hpp"


int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "top: " << mstack.top() << std::endl;

    std::cout << "pop: " << mstack.top() << std::endl;
    
    mstack.pop();
    
    std::cout << "top: " << mstack.top() << std::endl;

    std::cout << "size: " << mstack.size() << std::endl;

    mstack.push(3);
	mstack.push(5);
	mstack.push(737);
    mstack.push(42);
	mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin(); //iterator is an alias for std::deque<int>::iterator, returns an iterator pointing to the first element of the stack
	MutantStack<int>::iterator ite = mstack.end();
	
	++it; // ++it and --it are used to move the iterator to the next or previous element of the stack, it is used to iterate through the stack
	--it;

    std::cout << "mutant stack: ";
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

    std::cout << "regular stack: ";
	std::stack<int> s(mstack);
    std::stack<int> tempStack;
    
    while (!s.empty()) 
    {
        tempStack.push(s.top());
        s.pop();
    }

    while (!tempStack.empty()) 
    {
        std::cout << tempStack.top() << " ";
        tempStack.pop();
    }
    std::cout << std::endl;

    std::cout << "const iterator stack: ";
    MutantStack<int>::const_iterator cit = mstack.begin(); 
    MutantStack<int>::const_iterator cite = mstack.end();

    while (cit != cite)
    {
        std::cout << *cit << " ";
        ++cit;
    }
    std::cout << std::endl;
    std::cout << "try to add somethig using the const_iterator: ";
    //*cit = 2042;
    std::cout << "impossible to modify const" << std::endl;

    std::cout << "reverse iterator stack: ";
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();

    while (rit != rite)
    {
        std::cout << *rit << " ";
        ++rit;
    }
    std::cout << std::endl;

    std::cout << "const reverse iterator stack: ";
    MutantStack<int>::const_reverse_iterator crit = mstack.rbegin();
    MutantStack<int>::const_reverse_iterator crite = mstack.rend();

    while (crit != crite)
    {
        std::cout << *crit << " ";
        ++crit;
    }
    std::cout << std::endl;
    std::cout << "try to add somethig using the reverse_const_iterator: ";
    //*crit = 2042;
    std::cout << "impossible to modify const" << std::endl;

    return 0;

}