#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <ctime> //clock
#include <deque>
#include <cstdlib> //atoi
# include <algorithm> //inplace_merge
# include <iterator> //advance
# include <utility> //pair
# include <string> //string
# include <exception> //exception
#include <set>



void before_print(char **argv);
void pairing(std::list<std::pair<int, int> > *sort1, char **argv, int *if_arg_is_unpair_value);
void printer(const std::list<std::pair<int, int> > &sort1, int if_arg_is_unpair_value, const std::string &str);
void sorting(std::list< std::pair<int, int> > *sort1);
void mergSorting(std::list<std::pair<int, int> >::iterator start, std::list<std::pair<int, int> >::iterator end, size_t size);
bool compare_elements(std::pair<int, int> a, std::pair<int, int> b);
void init_resultList(std::list<int> *resultList, std::list<std::pair<int, int> > &sort1);
void resultList_print(std::list<int> &resultList);
void insert_resultList(std::list<std::pair<int, int> > sort1, std::list<int> *resultList, int if_arg_is_unpair_value);
void after_print(std::list<int> resultList);

void pairing2(std::deque<std::pair<int, int> > *sort2, char **argv, int *if_arg_is_unpair_value2);
void printer2(const std::deque<std::pair<int, int> > &sort2, int if_arg_is_unpair_value2, const std::string &str);
void sorting2(std::deque<std::pair<int, int> > *sort2);
void mergSorting2(std::deque<std::pair<int, int> >::iterator start, std::deque<std::pair<int, int> >::iterator end, size_t size);
void init_resultList2(std::deque<int> *resultList2, std::deque<std::pair<int, int> > sort2);
void resultList_print2(std::deque<int> &resultList2);
void binary_search_insertion2(std::deque<int> *resultList2, std::deque<int>::iterator end, int value);
void insert_resultList2(std::deque<std::pair<int, int> > sort2, std::deque<int> *resultList2, int if_arg_is_unpair_value2);
void after_print2(std::deque<int> resultList2);

bool is_non_negative_integer(const std::string& str);




#endif