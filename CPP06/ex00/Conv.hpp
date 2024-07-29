#ifndef CONV_HPP
#define CONV_HPP

#include <iostream>
#include <cmath>
#include <cstdlib>

#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define FLOAT_MAX 3.40282e+38
#define FLOAT_MIN -3.40282e+38
#define DOUBLE_MAX 1.79769e+308
#define DOUBLE_MIN -1.79769e+308

enum scal_type
{
    SPECIAL, 
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    INVALID
};

class ScalarConverter
{
    private:
        ScalarConverter(void);
        ScalarConverter(ScalarConverter const &obj);
        ~ScalarConverter(void);
        ScalarConverter &operator=(ScalarConverter const &obj);
    public:
        static void convert(const std::string &str);
}; 

scal_type	whichType(const std::string& str, size_t& len);
void printInvalid(const std::string &str);
void printSpecial(const std::string &str);
void charConvert(const std::string &str, size_t &len);
void intConvert(const std::string &str);
void floatConvert(const std::string &str);
void doubleConvert(const std::string &str);

int isSpecial(const std::string &str);
int isChar(const std::string &str, size_t &len);
int isInt(const std::string &str, size_t &len);
int isFloat(const std::string &str, size_t len, size_t &dot);


#endif