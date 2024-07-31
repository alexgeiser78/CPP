#include "Conv.hpp"

//-------------------converters----------------------//

void printInvalid(const std::string &str)
{
    std::cout << "Invalid input: " << str << std::endl;
}

void printSpecial(const std::string &str)
{
    if(str == "nan" || str == "nanf") // = not a number and not a number float (0/0, inf - inf, or -2^2)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (str == "+inf" || str == "+inff") // = positive infinity, double and simple-precision floating-point format 
    {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
    else if (str == "-inf" || str == "-inff") // = negative infinity, double and simple-precision floating-point format 
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

void charConvert(const std::string &str, size_t &len)
{
	char	c = 0;

	if (len == 1)
		c = str[0];
	else
		c = str[1];
	std::cout << "char: ";
	if (isprint(c))
	{
		std::cout << "'" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
	}
	else
		std::cout << "Non displayable" << std::endl;
}

void intConvert(const std::string &str)
{
    long big = std::atol(str.c_str()); //converts string to to a C-style string and then to a long int
    std::cout << "char: ";
    if (big < 0 || big > 127)
        std::cout << "impossible" << std::endl;
    
    else if (isprint(static_cast<char>(big))) // static_cast<char> converts the long int to a char
        std::cout << "'" << static_cast<char>(big) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    
    std::cout << "int: ";
    if (big > INT_MAX || big < INT_MIN)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(big) << std::endl;
    std::cout << "float: " << static_cast<float>(big) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(big) << ".0" << std::endl; 
}

void floatConvert(const std::string &str)
{
    float f = std::atof(str.c_str()); //ASCII to float
    bool  closeTof = std::fabs(f - static_cast<int>(f)) < 0.000001; //check if a floating-point number f is effectively an integer
                                                                           //computes the absolute difference between the number and the its integer part, made to have a tolerance               
    std::cout << "char: ";    
    if (f < 0 || f > 127)
        std::cout << "impossible" << std::endl;
    else if (isprint(static_cast<char>(f)))
        std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    
    std::cout << "int: ";
    if (static_cast<long>(f) < INT_MIN || static_cast<long>(f) > INT_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(f) << std::endl;
    
    std::cout << "float: ";
    if (f < FLOAT_MIN || f > FLOAT_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << f << (closeTof ? ".0f" : "f") << std::endl; //displays the float number, if closeTof is true, no fractional part is displayed
    std::cout << "double: " << static_cast<double>(f) << (closeTof ? ".0" : "") << std::endl; //displays the double number, if closeTof is true, no fractional part is displayed
}

void doubleConvert(const std::string &str)
{
    double d = std::atof(str.c_str());
    bool  closeTod = std::fabs(d - static_cast<int>(d)) < 1e-9;

    std::cout << "char: ";
    if (d < 0 || d > 127)
        std::cout << "impossible" << std::endl;
    else if (isprint(static_cast<char>(d)))
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    
    std::cout << "int: ";
    if (d < INT_MIN || d > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;

    std::cout << "float: ";
    if (d < FLOAT_MIN || d > FLOAT_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<float>(d) << (closeTod ? ".0f" : "f") << std::endl;
    std::cout << "double: ";
    if (d < DOUBLE_MIN || d > DOUBLE_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << d << (closeTod ? ".0" : "") << std::endl;
}

//----------------------checkers----------------------//

int isSpecial(const std::string &str)
{
    if ( str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" \
    || str == "-inf" || str == "-inff")
        return 1;
    return 0;
}

int isChar(const std::string &str, size_t &len)
{
    if (len == 1 && !isdigit (str[0]))
        return 1;
    if (len == 3 && str[0] == '\'' && str[2] == '\'') // check if the string is a single char in single quotes
        return 1;
    return 0;
}

int isInt(const std::string &str, size_t &len)
{
    size_t i = 0;
    int flag = 0;

    if (str[i] == '+' || str[i] == '-')
    {
        i++;
        flag = 1;
    }
    while ((str[i] && len > 0 && len < 12) || (str[i] && !flag && len > 0 && len < 11))
	{
		if (!isdigit(str[i]))
			return 0;
		i++;
    }
    return 1;
}
//len 12, because it is the limit of digits that the target data type can handle safely

int isFloat(const std::string &str, size_t len, size_t &dot)
{
    for (int j = dot - 1; j >= 0; j--) //checking the integer part
	{
		if (!isdigit(str[j]) && j != 0)
			return 0;
		if (!isdigit(str[j]) && j == 0 && str[j] != '+' && str[j] != '-')
			return 0;
	}
	for (size_t i = dot + 1; i < len; i++) //checking the fractional part
	{
		if (!isdigit(str[i]) && str[i] != 'f')
			return 0;
		if (str[i] == 'f' && i != len - 1)
			return 0;
	}
	return 1;
}
