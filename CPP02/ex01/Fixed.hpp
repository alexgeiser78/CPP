#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    private:
        int _value;
        static const int _frac;
    
    public:
        Fixed(void);
        ~Fixed(void);
        Fixed(Fixed const &copy);
		Fixed	&operator=(Fixed const &copy);
        Fixed(const int value);
		Fixed(const float value);
        int		getRawBits(void) const;
        int		toInt(void) const;
        float	toFloat(void) const;
};
        std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr); //overload of the operator << for Fixed objects, it takes a reference to an ostream object and a reference to a Fixed object


#endif