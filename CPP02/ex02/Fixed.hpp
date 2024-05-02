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
        Fixed(const int value);
        Fixed(const float value);
        
        Fixed	&operator=(Fixed const &copy);
        Fixed	operator+(Fixed const &copy) const;
		Fixed	operator-(Fixed const &copy) const;
		Fixed	operator*(Fixed const &copy) const;
		Fixed	operator/(Fixed const &copy) const;
        
        int		getRawBits(void) const;
        void	setRawBits(int const raw); 
        int		toInt(void) const;
        float	toFloat(void) const;
};
        std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr);

#endif