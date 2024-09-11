#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Bad request" << std::endl;
    }

    try
    {
        RPN rpn(argv[1]); //parametrised constructor
		std::cout << rpn.getResult() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n'; // std::cerr is used to print errors
    }
    return 0;
}

/*
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"

stack work:
                        42
                    +
                    1

                    41
                -
                4

                45
            -
            9

            54
        -
        9

        63
    -
    9
*
9
    72
8



*/