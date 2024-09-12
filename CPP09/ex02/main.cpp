#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
		std::cout << "Bad request" << std::endl;
        return(1);
    }

    std::cout << "1st container: LIST" << std::endl;
    clock_t start1 = clock();
    std::list< std::pair<int, int> > sort1; //list of a pair of 2 int
    std::list<int> resultList;
    //int if_arg_is_unpair_value = -1;
        
        try
        {
            before_print(argv);
            pairing(&sort1, argv);
            pairing_print(sort1);
            sorting(&sort1);
            sorting_print(sort1);
            //mergSorting(sort1.begin(), sort1.end());
            mergSorting_print(sort1);
            
            
            
            //after_print(resultList);
            
            clock_t end1 = clock();
            std::cout << "Time: " << static_cast<double>(end1 - start1) / 1000 <<" millisec" << std::endl;
        }

        catch (const std::exception &e)
        {
			std::cerr << e.what() << '\n';
	    }

    std::cout << "2nd container: DEQUE" << std::endl;
    clock_t start2 = clock();

        try
        {
            before_print(argv);
            clock_t end2 = clock();
            std::cout << "Time: " << static_cast<double>(end2 - start2) / 1000 <<" millisec" << std::endl;
        }

        catch (const std::exception &e)
        {
			std::cerr << e.what() << '\n';
	    }

    std::cout << "3rd container: VECTOR" << std::endl;
    clock_t start3 = clock();

        try
        {
            before_print(argv);
            clock_t end3 = clock();
            std::cout << "Time: " << static_cast<double>(end3 - start3) / 1000 <<" millisec" << std::endl;
        }

        catch (const std::exception &e)
        {   
            std::cerr << e.what() << '\n';
	    }

    





    return (0);
}


// why > > ?

//Ford Johnson algorithm: merge-insertion sort, which is a hybrid sorting algorithm, combining the best of both merge sort and insertion sort.
//The algorithm is as follows:
//1. Divide the array into n subarrays, each containing 1 element (a subarray of 1 element is considered sorted).
//2. Repeatedly merge subarrays to produce new sorted subarrays until there is only 1 subarray remaining.
//3. Insertion sort the final subarray.
//The algorithm is efficient for small arrays, as insertion sort is faster than merge sort for small arrays. The algorithm is also stable, meaning that the relative order of equal elements is preserved.