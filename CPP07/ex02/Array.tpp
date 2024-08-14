#ifndef ARRAY_TPP
#define ARRAY_TPP

// Constructors
template <typename T>
Array<T>::Array() : _arr(NULL), _size(0)
{
    std::cout << "Array default constructor called" << std::endl;
}

// Methods
template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}



#endif