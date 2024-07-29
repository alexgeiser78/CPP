#include "Conv.hpp" 

//----------------------constructor - destructor - assignator----------------------//

ScalarConverter::ScalarConverter(void)
{
    std::cout << "ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &obj)
{
    *this = obj;
}

ScalarConverter::~ScalarConverter(void)
{
    std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &obj)
{
    (void)obj;
    return *this;
}

//----------------------methods----------------------//

void ScalarConverter::convert(const std::string &str)
{
    size_t  len = str.length();
    scal_type  type = whichType(str, len);

     switch(type)
 {
    case INVALID:
        printInvalid(str);
        break;
    case SPECIAL:
        printSpecial(str);
        break; 
    case CHAR:
        charConvert(str, len);
        break;
    case INT:
        intConvert(str);
        break;  
    case FLOAT:
        floatConvert(str);
        break;
    case DOUBLE:
        doubleConvert(str);
        break;  
 }
}

scal_type	whichType(const std::string& str, size_t& len)
{
    size_t dot = str.find('.');
    size_t f = str.find('f');
    //std::cout << "dot position: " << dot << std::endl; //
    //std::cout << "f position: " << f << std::endl; //
     if (dot == std::string::npos) // npos = maximum possible value for an element of type size_t, common use with "find" method
    {
        if (isSpecial(str))
            return SPECIAL;
        if (isChar(str, len))
            return CHAR;
        if (isInt(str, len))
            return INT;
    }
    if (f != std::string::npos && dot != std::string::npos) // check if there is a . and a f in the string
    {
        if (isFloat(str, len, dot))
            return FLOAT;
    }
    else if (f == std::string::npos && dot != std::string::npos)
            return DOUBLE;
    return INVALID;
}
//npos = true if the string is not found

