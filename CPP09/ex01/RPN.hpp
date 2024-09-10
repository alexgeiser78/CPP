#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>

class RPN
{
    private:
        

    public:
            //constructors
            RPN();
            RPN(const std::string &str);
            RPN(const RPN &other);
		    RPN &operator=(const RPN &other);
		    ~RPN();

            //Getters
            int getResult() const;

            //member functions
            int plus(int a, int b);
            int minus(int a, int b);
            int multiply(int a, int b);
            int divide(int a, int b);

            //exceptions


};



#endif