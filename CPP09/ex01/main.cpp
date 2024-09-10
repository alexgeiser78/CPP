#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Bad request" << std::endl;
    }

    try
    {
        RPN rpn(argv[1]);
		std::cout << rpn.getResult() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}