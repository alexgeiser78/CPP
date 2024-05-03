#include "Fixed.hpp"

static	float PfloattoInt(float base, int exp) //it converts a float number to an integer, it takes a base and an exponent, if the exponent is negative, it divides the base by the exponent, if the exponent is positive, it multiplies the base by the exponent
{
	float	result;

	if (!exp)  //if the exponent is 0, it returns 1
		return (1);
	if (exp < 0)
	{
		base = 1 / base; //if the exponent is negative, it inverts the base
		exp *= -1; //and makes the exponent positive
	}
	result = base;
	while (--exp)
		result *= base;
	return (result);
}

const int	Fixed::_frac = 8; //static variable of type const int and class Fixed, initialized to 8, _frac wont change during the program execution, shared by all instances of the class Fixed, numbers with fix comma are represented by 8 bits after the comma, this means values stored in the Fixed class will have 8 bits reserved for the decimal part 

//--------------constructors----------------

Fixed::Fixed(void): _value(0)
{
	std::cout << "Default constructor called" << std::endl; 
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl; 
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int value): _value(value * PfloattoInt(2, this->_frac))
{  
	std::cout << "Int constructor called" << std::endl; 
	_value = value << _frac; //shift to the left by _frac bits, converts the integer value to a fixed point number
} 

Fixed::Fixed(const float value): _value(value * PfloattoInt(2, this->_frac)) //it initializes the _value variable with the value passed as argument, it multiplies the value by 2^_frac, it is the same as shifting the value to the left by _frac bits
{  
	std::cout << "Float constructor called" << std::endl; 
	_value = roundf(value * (1 << _frac)); // << is the left shift operator, it shifts the value to the left by _frac bits, it is the same as multiplying the value by 2^_frac, roundf rounds the value to the nearest integer value
}

//--------------functions----------------

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}

int	Fixed::toInt(void) const //fixed point number to integer conversion
{
	return (this->_value * PfloattoInt(2, -this->_frac)); //-this->_frac is the exponent, it is negative because the number is fixed and the decimal part is represented by 8 bits, it returns the integer part of the number
}

float	Fixed::toFloat(void) const   //fixed point number to float point number conversion
{
	return (this->_value * PfloattoInt(2, -this->_frac));
}

//--------------operators----------------

Fixed	&Fixed::operator=(Fixed const &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = copy.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(Fixed const &copy) const
{
	Fixed	result(this->toFloat() + copy.toFloat());
	return (result);
}

Fixed	Fixed::operator-(Fixed const &copy) const
{
	Fixed	result(this->toFloat() - copy.toFloat());
	return (result);
}

Fixed	Fixed::operator*(Fixed const &copy) const
{
	Fixed	result(this->toFloat() * copy.toFloat());
	return (result);
}

Fixed	Fixed::operator/(Fixed const &copy) const
{
	Fixed	result(this->toFloat() / copy.toFloat());
	return (result);
}

//--------------increment and decrement operators----------------

Fixed	&Fixed::operator++(void) //++a
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	
	return (*this);
}

Fixed	Fixed::operator++(int value) //a++
{
	Fixed	aux;

	aux = *this;

	if (!value)
		value = 1;
	this->setRawBits(this->getRawBits() + value);
	return (aux);
}

Fixed	Fixed::operator--(int value)
{
	Fixed	aux;

	aux = *this;

	if (!value)
		value = 1;
	this->setRawBits(this->getRawBits() - value);
	return (aux);
}


//--------------min and max functions----------------

const Fixed	&Fixed::min(Fixed const &val1, Fixed const &val2)
{
	if (val1 < val2)
		return (val1);
	return (val2);
}

const Fixed	&Fixed::max(Fixed const &val1, Fixed const &val2)
{
	if (val1 > val2)
		return (val1);
	return (val2);
}

//--------------comparison operators----------------

bool	Fixed::operator==(const Fixed &copy) const
{
	return (this->toFloat() == copy.toFloat());
}

bool	Fixed::operator!=(const Fixed &copy) const
{
	return (this->toFloat() != copy.toFloat());
}

bool	Fixed::operator<=(const Fixed &copy) const
{
	return (this->toFloat() <= copy.toFloat());
}

bool	Fixed::operator>=(const Fixed &copy) const
{
	return (this->toFloat() >= copy.toFloat());
}

bool	Fixed::operator<(const Fixed &copy) const
{
	return (this->toFloat() < copy.toFloat());
}

bool	Fixed::operator>(const Fixed &copy) const
{
	return (this->toFloat() > copy.toFloat());
}

//--------------stream----------------

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr)  // definition of the operator <<, it takes a reference to an ostream object and a reference to a Fixed object, it returns a reference to an ostream object
{
	return (str << fixed_nbr.toFloat()); //it returns the float value of the Fixed object
}

