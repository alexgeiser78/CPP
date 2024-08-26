#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque> 


int main(void)
{
    std::cout << "-vector:" << std::endl;
    std::vector<int> vec; //dynamic array of int 
    int i = 0;

    while(i < 10)
    {
        vec.push_back(i); //used to add an element to the end of the container and the container size is increased by 1
        i++;
    }
    try
	{
		std::cout << *easyfind(vec, 5) << std::endl; //dereference the iterator returned by easyfind
		std::cout << *easyfind(vec, 11) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

    std::cout << "-list:" << std::endl;
    std::list<int> lst; //list of int
    int j = 0;

    while(j < 10)
    {
        lst.push_back(j);
        j++;
    }
    try
    {
        std::cout << *easyfind(lst, 6) << std::endl;
        std::cout << *easyfind(lst, 12) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "-deque:" << std::endl;
    std::deque<int> deq; ////double-ended queue of int, push at the front and back
    int k = 0;

    while(k < 5)
    {
        deq.push_front(k);
        k++;
    }

    while(k < 10)
    {
        deq.push_back(k);
        k++;
    }
    try
	{
		std::cout << *easyfind(deq, 7) << std::endl;
		std::cout << *easyfind(deq, 13) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}    
    return (0);
}

//container "forward_list" is C11
//container "queue", "stack", "priority_queue" is not iterable