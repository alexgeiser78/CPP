#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm> //std::find 
# include <exception>
# include <iostream>

class NotFoundException : public std::exception
{
public:
    const char *what () const throw () //redifine the what method of the exception class, return a pointer to a const char
    {
        return "Element not found";
    }
};


template <typename T> //template function able to work with any type of container, as long as it has iterators
typename T::iterator easyfind(T &container, int n) //easyfind function returns an iterator "T::iterator". Typename is necessary to indicate that T::iterator is a type
{
    typename T::iterator iter; //declare an iterator of type T used to iterate through the container

    iter = std::find(container.begin(), container.end(), n); //find method, search n in the container "container", returns an iterator pointing to the first element in the range [first, last). If no n is found, the function returns last.
    if (iter == container.end()) //container.end != last element of the container, it is the element after the last element of the container  
		{
        std::cout << n << ": ";
                throw NotFoundException();
        }
    return (iter);
} 

#endif