# include "PmergeMe.hpp"

void before_print(char **argv)
{
    std::cout << "Before: ";
        for (int i = 1; argv[i]; i++)
        {
            std::cout << argv[i] << " ";
        }
        std::cout << std::endl;
}

void pairing(std::list<std::pair<int, int> > *sort1, char **argv)
{
    int i  = 1;

    while (argv[i])
    {
        if (argv[i] && argv[i + 1]) //check if there remains 2 values
        {
            /*sort1->push_back(std::make_pair(std::atoi(argv[i]), std::atoi(argv[i + 1])));
            i += 2;*/
            std::pair<int, int> pair_temp(std::atoi(argv[i]), std::atoi(argv[i + 1])); //atoi conv and make_pair
            sort1->push_back(pair_temp); //insert pair_temp to sort1
            i += 2; //increment i by 2 since 2 values have been paired
        }
        else
        {
            throw std::invalid_argument("unpair value");
        }
    }
}

void pairing_print(const std::list<std::pair<int, int> > &sort1)
{
    std::cout << "pairing_print: " << std::endl;
    std::list<std::pair<int, int> >::const_iterator it;
    for (it = sort1.begin(); it != sort1.end(); ++it)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
}

void sorting(std::list<std::pair<int, int> > *sort1) //arg is a pointer to a list of pairs
{
    std::list<std::pair<int, int> >::iterator it = sort1->begin(); // Iterator init

    while (it != sort1->end()) // while iterator is not at the end of the list
    {
        if (it->first > it->second) // If the first value is greater than the second
        {
            int temp = it->first;
            it->first = it->second;
            it->second = temp; //standard swap
        }
        ++it;
    }
}

void sorting_print(const std::list<std::pair<int, int> > &sort1)
{
    std::cout << "sorting_print: " << std::endl;
    std::list<std::pair<int, int> >::const_iterator it;
    for (it = sort1.begin(); it != sort1.end(); ++it)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
}
/*
void mergSorting(std::list<std::pair<int, int> >::iterator start, std::list<std::pair<int, int> >::iterator end) //Ford Johnson merge sort, split the list into 2, sort each half, then merge them
{
    size_t size = std::distance(start, end); //size of the list
    //if (size <= 1)
      //  return;

    size_t firstHalf = size / 2; //size of the first half
    //size_t secondHalf = size - firstHalf;

    std::list<std::pair<int, int> >::iterator middle = start; //iterator middle is at the start of the list
    std::advance(middle, firstHalf); //advance middle by firstHalf

    mergSorting(start, middle); //recursive call to sort the first half
    mergSorting(middle, end); //recursive call to sort the second half

    //std::inplace_merge(start, middle, end, &custom_cmp);


}*/

void mergSorting_print(const std::list<std::pair<int, int> > &sort1)
{
    std::cout << "mergSorting_print: " << std::endl;
    std::list<std::pair<int, int> >::const_iterator it;
    for (it = sort1.begin(); it != sort1.end(); ++it)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
}

void after_print(std::list<int> resultList)
{
	std::cout << "After: ";
	for (std::list<int>::iterator it = resultList.begin(); it != resultList.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << '\n';
}
