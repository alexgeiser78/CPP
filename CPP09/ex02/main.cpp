#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
		std::cout << "Bad request" << std::endl;
        return(1);
    }

        std::cout << "Before: ";
        for (int i = 1; i < argc; i++)
        {
            std::cout << argv[i] << " ";
        }
        std::cout << std::endl;
        
        //std::vector<int> v1;

        clock_t start = clock();

        clock_t end = clock();

        std::cout << "Time: " << static_cast<double>(end - start) / 1000 <<" millisec" << std::endl;





    return (0);
}