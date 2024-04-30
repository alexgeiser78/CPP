# ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
    private:
       // int					_value;
	   // static const int	_frac;

    public:
        Fixed(void); //default constructor canonical
		~Fixed(void); //destructor canonical
		Fixed(Fixed const &copy); //copy constructor canonical, creates a deep copy of the object passed as parameter, useful for dynamic memory allocation and agrregation by reference or by value
		Fixed	&operator=(Fixed const &copy); //(operator=)assignation operator overload canonical, this operator is called when an already initialized object is assigned a new value from another object, it creates a deep copy of the object passed as parameter, useful for dynamic memory allocation and agrregation by reference or by value
		//int		getRawBits(void) const;
		//void	setRawBits(int const raw);
};

#endif