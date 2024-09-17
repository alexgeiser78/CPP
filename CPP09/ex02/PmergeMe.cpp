# include "PmergeMe.hpp"


bool is_non_negative_integer(const std::string& str) 
{
    if (str.empty()) 
        return false;

    std::string::const_iterator it = str.begin();
    std::string::const_iterator end = str.end();

    while (it != end) 
    {
        if (!std::isdigit(*it))     
            return false;
        ++it;
    }
    return true;
}

void before_print(char **argv) 
{
    std::set<int> seen; //set to store and sort the values and check for duplicates
    std::cout << "Before: ";
    for (int i = 1; argv[i]; i++) 
    {
        std::string arg = argv[i];
        if (!is_non_negative_integer(arg)) 
        {
            std::cerr << "Error: Invalid input \"" << arg << "\". All inputs must be non-negative integers." << std::endl;
            exit(EXIT_FAILURE);
        }
        int value = std::atoi(argv[i]);
        if (seen.find(value) != seen.end()) 
        {
            std::cerr << "Error: Duplicate value detected \"" << value << "\"." << std::endl;
            exit(EXIT_FAILURE);
        }
        seen.insert(value);
        std::cout << argv[i] << " ";
    }
    std::cout << std::endl;
}

void pairing(std::list<std::pair<int, int> > *sort1, char **argv, int *if_arg_is_unpair_value) 
{
    int i = 1;

    while (argv[i]) 
    {
        if (argv[i] && argv[i + 1]) 
        {
            std::pair<int, int> pair_temp(std::atoi(argv[i]), std::atoi(argv[i + 1]));
			sort1->push_back(pair_temp);
			i += 2;
        }
        else 
        {
            *if_arg_is_unpair_value = std::atoi(argv[i]);
            i++;
        }
    }
}

void printer(const std::list<std::pair<int, int> > &sort1, int if_arg_is_unpair_value, const std::string &str)
{
    std::cout << str << std::endl;
    std::list<std::pair<int, int> >::const_iterator it;
    for (it = sort1.begin(); it != sort1.end(); ++it)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
    if (if_arg_is_unpair_value != -1)
    {
        std::cout << if_arg_is_unpair_value << " X" << std::endl;
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

bool compare_elements(std::pair<int, int> a, std::pair<int, int> b)
{
    if (a.second < b.second) //compare the second value of the pair
        return (true);
    return(false);
}

void mergSorting(std::list<std::pair<int, int> >::iterator start, std::list<std::pair<int, int> >::iterator end, size_t size) //Ford Johnson merge sort, split the list into 2, sort each half, then merge them
{
    if (size == 0 && start != end)
		size = std::distance(start, end);
	if (size <= 1)
		return;

    size_t firstHalf = size / 2; //size of the first half
    size_t secondHalf = size - firstHalf;

    std::list<std::pair<int, int> >::iterator middle = start; //iterator middle is at the start of the list
    std::advance(middle, firstHalf); //advance middle by firstHalf

    mergSorting(start, middle, firstHalf); //recursive call to sort the first half
    mergSorting(middle, end, secondHalf); //recursive call to sort the second half

    std::inplace_merge(start, middle, end, &compare_elements); // 3 iterators (st, mid, end), fusion of the 2 halves

}

void init_resultList(std::list<int> *resultList, std::list<std::pair<int, int> > &sort1)
{
    for (std::list<std::pair<int, int> >::iterator it = sort1.begin(); it != sort1.end(); ++it)
		resultList->push_back(it->second); //iterate through the list "sort1" and push the second value of each pair to resultList

	if (!sort1.empty())
		resultList->push_front(sort1.begin()->first); //if sort1 is not empty, push the first value of the first pair to the front of resultList
}
// work flow
//sort1 = {3, 5}, {1, 6}, {2, 8}
//resultList = {5, 6, 8} (for)
//resultList = {3, 5, 6, 8} (if!)

void binary_search_insertion(std::list<int> *resultList, std::list<int>::iterator end, int value)
{
    std::list<int>::iterator place_to_insert_it = std::lower_bound(resultList->begin(), end, value); //find the position to insert the value
    resultList->insert(place_to_insert_it, value); //insert the value
    //std::cout << "Inserting value: " << value << " into resultList at position: " << std::distance(resultList->begin(), place_to_insert_it) << std::endl;
}

void insert_resultList(std::list<std::pair<int, int> > sort1, std::list<int> *resultList, int if_arg_is_unpair_value)
{
    size_t Jacobsthal[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765}; //Jacobsthal sequence (a, b, c) = 2a + b = c
    int jacobsthal_index = 1; //index of the Jacobsthal sequence
    
    std::list<int>::iterator insert_index_finder_it; //iterator to find the index to insert the unpaired value
	std::list<std::pair<int, int> >::iterator sort1_pair_it;
	std::list<std::pair<int, int> >::iterator last_jacob_insert_it = sort1.begin(); //iterator to the last pair where a Jacobsthal number was inserted
    
    while (Jacobsthal[jacobsthal_index] <=  sort1.size()) //loop to find the index of the Jacobsthal number that is smaller or equal to the size of sort1 (3 pairs = 3) (4 pairs = 3)
	{
		sort1_pair_it = sort1.begin();
		std::advance(sort1_pair_it, Jacobsthal[jacobsthal_index] - 1); //positions the iterator "sort1_pair_it" at the Jacobsthal number
        
        //std::cout << "Jacobsthal index: " << Jacobsthal[jacobsthal_index] << " | Inserting pair: (" << sort1_pair_it->first << ", " << sort1_pair_it->second << ")" << std::endl;
        
        last_jacob_insert_it = sort1_pair_it; //stores the iterator "sort1_pair_it" at the last Jacobsthal number

        int insertion_counter = 0; //counter to keep track of the number of insertions
		while (Jacobsthal[jacobsthal_index] - insertion_counter > Jacobsthal[jacobsthal_index - 1])  //loop to insert the Jacobsthal number and the previous Jacobsthal numbers
		{
			insert_index_finder_it = std::find(resultList->begin(), resultList->end(), sort1_pair_it->second);
			binary_search_insertion(resultList, insert_index_finder_it, sort1_pair_it->first);
			//std::cout << "Inserting first of pair: " << sort1_pair_it->first << std::endl;
            //resultList_print(*resultList);
            sort1_pair_it--;
			insertion_counter++;
            //std::cout << "insertion_counter: " << insertion_counter << std::endl;
		}
        jacobsthal_index++;

	}
    if (Jacobsthal[jacobsthal_index] != sort1.size())
	{
		sort1_pair_it = sort1.end();
		if (sort1_pair_it != sort1.begin())
			sort1_pair_it--;
		while (sort1_pair_it != last_jacob_insert_it)
		{
			insert_index_finder_it = std::find(resultList->begin(), resultList->end(), sort1_pair_it->second);
			//std::cout << "Inserting remaining pair: (" << sort1_pair_it->first << ", " << sort1_pair_it->second << ")" << std::endl;
            binary_search_insertion(resultList, insert_index_finder_it, sort1_pair_it->first);
			sort1_pair_it--;
		}
    }

	if (if_arg_is_unpair_value != -1)
	{
        //std::cout << "Inserting unpaired value: " << if_arg_is_unpair_value << std::endl;
		binary_search_insertion(resultList, resultList->end(), if_arg_is_unpair_value);
	}
    
}
//Jacobstahl says where to insert the first value of the pair, more efficiency

void resultList_print(std::list<int> &resultList)
{
    //std::cout << "resultList_print: " << std::endl;
    std::list<int>::iterator it;
    for (it = resultList.begin(); it != resultList.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
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

//DEQUE

void pairing2(std::deque<std::pair<int, int> > *sort2, char **argv, int *if_arg_is_unpair_value2) 
{
    int i = 1;

    while (argv[i]) 
    {
        if (argv[i] && argv[i + 1]) 
        {
            std::pair<int, int> pair_temp(std::atoi(argv[i]), std::atoi(argv[i + 1]));
            sort2->push_back(pair_temp);
            i += 2;
        }
        else 
        {
            *if_arg_is_unpair_value2 = std::atoi(argv[i]);
            i++;
        }
    }
}


void printer2(const std::deque<std::pair<int, int> > &sort2, int if_arg_is_unpair_value, const std::string &str)
{
    std::cout << str << std::endl;
    std::deque<std::pair<int, int> >::const_iterator it;
    for (it = sort2.begin(); it != sort2.end(); ++it)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
    if (if_arg_is_unpair_value != -1)
    {
        std::cout << if_arg_is_unpair_value << " X" << std::endl;
    }
}

void sorting2(std::deque<std::pair<int, int> > *sort2)
{
	for (std::deque<std::pair<int, int> >::iterator it = sort2->begin(); it !=sort2->end(); ++it)
	{
		if (it->first > it->second)
		{
			int temp = it->first;
			it->first = it->second;
			it->second = temp;
		}
	}
}

void mergSorting2(std::deque<std::pair<int, int> >::iterator start, std::deque<std::pair<int, int> >::iterator end, size_t size)
{
	if (size == 0 && start != end)
		size = std::distance(start, end);
	if (size <= 1)
		return;

	size_t firstHalf = size / 2;
	size_t secondHalf = size - firstHalf;
	std::deque<std::pair<int, int> >::iterator middle = start + firstHalf;

	mergSorting2(start, middle, firstHalf);
	mergSorting2(middle, end, secondHalf);
	std::inplace_merge(start, middle, end, &compare_elements);
}

void init_resultList2(std::deque<int> *resultList2, std::deque<std::pair<int, int> > sort2)
{
	for (std::deque<std::pair<int, int> >::iterator it = sort2.begin(); it != sort2.end(); ++it)
		resultList2->push_back(it->second);
	if (!sort2.empty())
		resultList2->push_front(sort2.begin()->first);
}

void resultList_print2(std::deque<int> &resultList2)
{
    //std::cout << "resultList_print2: " << std::endl;
    std::deque<int>::iterator it;
    for (it = resultList2.begin(); it != resultList2.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void binary_search_insertion2(std::deque<int> *resultList2, std::deque<int>::iterator end, int value)
{
	std::deque<int>::iterator place_to_insert = std::lower_bound(resultList2->begin(), end, value);
	resultList2->insert(place_to_insert, value);
}

void insert_resultList2(std::deque<std::pair<int, int> > sort2, std::deque<int> *resultList2, int if_arg_is_unpair_value2)
{
    size_t Jacobsthal2[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765}; //Jacobsthal sequence (a, b, c) = 2a + b = c
    int jacobsthal_index2 = 1; //index of the Jacobsthal sequence
    
    std::deque<int>::iterator insert_index_finder_it2; //iterator to find the index to insert the unpaired value
	std::deque<std::pair<int, int> >::iterator sort2_pair_it;
	std::deque<std::pair<int, int> >::iterator last_jacob_insert_it2 = sort2.begin(); //iterator to the last pair where a Jacobsthal number was inserted
    
    // Loop to find the Jacobsthal number that is smaller or equal to the size of sort2
    while (Jacobsthal2[jacobsthal_index2] <= sort2.size()) 
	{
		sort2_pair_it = sort2.begin() + (Jacobsthal2[jacobsthal_index2] - 1);
		last_jacob_insert_it2 = sort2_pair_it; // Store the iterator at the last Jacobsthal number
        
        //std::cout << "Jacobsthal index: " << Jacobsthal2[jacobsthal_index2] << " | Inserting pair: (" << sort2_pair_it->first << ", " << sort2_pair_it->second << ")" << std::endl;
        int insertion_counter2 = 0; // Counter to keep track of the number of insertions

		while (Jacobsthal2[jacobsthal_index2] - insertion_counter2 > Jacobsthal2[jacobsthal_index2 - 1])  
		{
			insert_index_finder_it2 = std::find(resultList2->begin(), resultList2->end(), sort2_pair_it->second);
			binary_search_insertion2(resultList2, insert_index_finder_it2, sort2_pair_it->first);
			//std::cout << "Inserting first of pair: " << sort2_pair_it->first << std::endl;
            ///resultList_print2(*resultList2);
            sort2_pair_it--;
			insertion_counter2++;
            //std::cout << "insertion_counter: " << insertion_counter2 << std::endl;
		}
        jacobsthal_index2++;
	}

    if (Jacobsthal2[jacobsthal_index2] != sort2.size())
	{
		sort2_pair_it = sort2.end();
		if (sort2_pair_it != sort2.begin())
			sort2_pair_it--;
		while (sort2_pair_it != last_jacob_insert_it2)
		{
			insert_index_finder_it2 = std::find(resultList2->begin(), resultList2->end(), sort2_pair_it->second);
			//std::cout << "Inserting remaining pair: (" << sort2_pair_it->first << ", " << sort2_pair_it->second << ")" << std::endl;
            binary_search_insertion2(resultList2, insert_index_finder_it2, sort2_pair_it->first);
			sort2_pair_it--;
		}
    }

	if (if_arg_is_unpair_value2 != -1)
	{
        //std::cout << "Inserting unpaired value: " << if_arg_is_unpair_value2 << std::endl;
		binary_search_insertion2(resultList2, resultList2->end(), if_arg_is_unpair_value2);
	}
}


void after_print2(std::deque<int> resultList2)
{
	std::cout << "After: ";
	for (std::deque<int>::iterator it = resultList2.begin(); it != resultList2.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << '\n';
}



