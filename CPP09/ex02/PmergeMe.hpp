#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <cstdlib> //atoi


void before_print(char **argv);
void pairing(std::list<std::pair<int, int> > *sort1, char **argv);
void pairing_print(const std::list<std::pair<int, int> > &sort1);
void sorting(std::list< std::pair<int, int> > *sort1);
void sorting_print(const std::list<std::pair<int, int> > &sort1);
void mergSorting(std::list<std::pair<int, int> >::iterator start, std::list<std::pair<int, int> >::iterator end);
void mergSorting_print(const std::list<std::pair<int, int> > &sort1);


//void after_print(std::list<int> &resultList);

#endif