#ifndef RPN_HPP
#define RPN_HPP

# include <iostream>
# include <stack> // RPN works with numbers first than operators (5 3 +) so it's logical to use stack
# include <exception>
# include <stdexcept> // std::runtime_error
# include <sstream>

class RPN //reverse polish notation
{
    private:
            std::stack<int> stack;
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
            void calcStack(int (RPN::*f)(int, int));

            //exceptions

            class divisionByZero : public std::runtime_error // runtime error is better than exception because it's specific for logic and calculation errors
		{
			public:
				explicit divisionByZero(const std::string& msg); //explicit is used to avoid automatic conversions (const char* to std::string), makes the code more readable. There is need to use a constructor
		};

        class missingNumbers : public std::runtime_error
		{
			public:
				explicit missingNumbers(const std::string& msg);
		};

        class emptyStack : public std::runtime_error
		{
			public:
				explicit emptyStack(const std::string& msg);
		};

        class invalidArgument : public std::runtime_error
		{
			public:
				explicit invalidArgument(const std::string& msg);
		};


};



#endif