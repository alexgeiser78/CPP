#include "Fixed.hpp"

const int	Fixed::_frac = 8; //static variable of type const int and class Fixed, initialized to 8, _frac wont change during the program execution, shared by all instances of the class Fixed, numbers with fix comma are represented by 8 bits after the comma, this means values stored in the Fixed class will have 8 bits reserved for the decimal part 

Fixed::Fixed(void): _value(0)
{
	std::cout << "Default constructor called" << std::endl; 
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl; 
}

Fixed::Fixed(Fixed const & copy)  //copy constructor
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy; //assignation operator, copies the value of the object copy to the object creation, it make a true copy of the object copy
}

Fixed	&Fixed::operator=(const Fixed &copy)  //returns a reference to the object Fixed, 
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = copy.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}
