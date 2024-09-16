#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <cstdlib> //atoi
# include <algorithm> //inplace_merge


void before_print(char **argv);
void pairing(std::list<std::pair<int, int> > *sort1, char **argv, int *if_arg_is_unpair_value);
void pairing_print(const std::list<std::pair<int, int> > &sort1, int if_arg_is_unpair_value);
void sorting(std::list< std::pair<int, int> > *sort1);
void sorting_print(const std::list<std::pair<int, int> > &sort1, int if_arg_is_unpair_value);
void mergSorting(std::list<std::pair<int, int> >::iterator start, std::list<std::pair<int, int> >::iterator end, size_t size);
void mergSorting_print(const std::list<std::pair<int, int> > &sort1, int if_arg_is_unpair_value);
bool compare_elements(std::pair<int, int> a, std::pair<int, int> b);
void init_resultList(std::list<int> *resultList, std::list<std::pair<int, int> > &sort1);
void resultList_print(std::list<int> &resultList);
void insert_resultList(std::list<std::pair<int, int> > sort1, std::list<int> *resultList, int if_arg_is_unpair_value);


void after_print(std::list<int> resultList);



#endif