#ifndef ARRAY_TPP
#define ARRAY_TPP

// Constructors
template <typename T>
Array<T>::Array() : _arr(NULL), _size(0)
{
    std::cout << "Array default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]()), _size(n) //new T[n]() creates an array of n elements of type T and initializes them to default value   
{
    std::cout << "Array parameter constructor called with " << n << " elements" << std::endl;
}

template <typename T>
Array<T>::Array(Array const &copy) : _arr(new T[copy._size]), _size(copy._size)
{
	unsigned int i = 0;
    while(i < _size)
    {
        _arr[i] = copy._arr[i];
        i++;
    }
    std::cout << "Array copy constructor called" << std::endl;
}

template <typename T>
Array<T>::~Array()
{
	delete [] _arr;  //specific array destructor
    std::cout << "Array destructor called" << std::endl;
}

// Operators

template <typename T>
Array<T> &Array<T>::operator=(Array const &copy)
{
    unsigned int i = 0;
	if (this != &copy)
	{
		delete [] _arr;
		_size = copy._size;
		_arr = new T[_size];
        while(i < _size)
        {
            _arr[i] = copy._arr[i];
            i++;
        }
	}
    std::cout << "Array assignation operator called" << std::endl;
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw OutOfBounds();
	return (_arr[i]);
}

template <typename T>
T const &Array<T>::operator[](unsigned int i) const
{
	if (i >= _size)
		throw OutOfBounds();
	return (_arr[i]);
}


// Methods
template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}

template <typename T>
const char *Array<T>::OutOfBounds::what() const throw()
{
	return ("Index out of bounds");
}

#endif