#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename T>  //typename T tells the compiler that T is a placeholder for any type that will be provided when the function is called.
                      //T could only be one type not multiple types in this case.
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T min(const T &a, const T &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

template<typename T>
T max(const T &a, const T &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

#endif