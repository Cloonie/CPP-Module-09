#pragma once

// Normal Libraries
#include <iostream>		// std::cout
#include <iomanip>		// std::setw
#include <ctime>		// clock()

// STL Libraries
#include <algorithm>	// std::merge & atoi
#include <vector>		// std::vector
#include <deque>		// std::deque

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& ref);
		PmergeMe& operator=(const PmergeMe& ref);

		void	pmergeme(char **argv);

		template <class Container>
		void display_elements(Container& con)
		{
			typedef		typename Container::iterator	it;
			for (it i = con.begin(); i != con.end(); ++i)
				std::cout << *i << " ";
			std::cout << std::endl;
		}

		template <class Container>
		void mergeInsertionSort(Container& con)
		{
			if (con.size() <= 5)
			{
				// insertion sort for small set of numbers
				for (size_t i = 1; i < con.size(); ++i)
				{
					int tmp = con[i];
					size_t j = i + 1;
					while (--j > 0 && con[j - 1] > tmp)
						con[j] = con[j - 1];
					con[j] = tmp;
				}
			}
			else
			{
				// split insert then merge for bigger sets of numbers
				typename Container::iterator middle = con.begin();
				std::advance(middle, con.size() / 2);
				Container left(con.begin(), middle);
				Container right(middle, con.end());

				mergeInsertionSort(left);
				mergeInsertionSort(right);

				con.clear();
				std::merge(left.begin(), left.end(),
					right.begin(), right.end(), std::back_inserter(con));
			}
		}
};