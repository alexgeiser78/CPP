#include "Conv.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "In order to convert something, enter a data!" << std::endl;
        return 0;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}