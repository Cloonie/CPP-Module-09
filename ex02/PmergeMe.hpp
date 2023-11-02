#pragma once

// Normal Libraries
#include <iostream>		// std::cout
#include <iomanip>		// std::setw
#include <ctime>		// clock()

// STL Libraries
#include <algorithm>	// std::merge & atoi
#include <vector>		// std::vector
#include <list>			//std::list

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& ref);
		PmergeMe& operator=(const PmergeMe& ref);
};