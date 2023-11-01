#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& ref) { *this = ref; }
PmergeMe& PmergeMe::operator=(const PmergeMe& ref) { (void)ref; return (*this); }

// void PmergeMe::sort(char **argv)
// {

// }