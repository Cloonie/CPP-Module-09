#pragma once

#include <iostream>
#include <string>
#include <cstdlib>

#include <vector>
#include <list>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& ref);
		PmergeMe& operator=(const PmergeMe& ref);

		// void PmergeMe::sort(char **argv);

	private:

};