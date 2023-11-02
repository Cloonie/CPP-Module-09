#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& ref) { *this = ref; }
PmergeMe& PmergeMe::operator=(const PmergeMe& ref) { (void)ref; return (*this); }

void	PmergeMe::pmergeme(char **argv)
{
	// initialize containers
	std::vector<int> vec;
	for (int i = 1; argv[i]; ++i)
	{
		int num = atoi(argv[i]);
		if (num >= 0)
			vec.push_back(num);
		else
		{
			std::cerr << "Error: numbers are not positive" << std::endl;
			return ;
		}
	}
	std::deque<int> dq(vec.begin(), vec.end());

	// output set of numbers in containers before and after sorting
	std::cout << "\033[1;31m" << "Before: ";
	display_elements(vec);
	std::cout << "\033[0m";
	mergeInsertionSort(vec);
	std::cout << "\033[1;32m" << "After: ";
	display_elements(vec);
	std::cout << "\033[0m";

	// output time taken to sort in both containers
	std::cout << "\033[1;36m";

	clock_t start1 = clock();
	mergeInsertionSort(vec);
	clock_t end1 = clock();
	double time1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000;

	std::cout << "Time to process a range of " << std::setw(3)
		<< vec.size() << " elements with std::vector : "
		<< std::fixed << std::setprecision(5) << time1 << " us" << std::endl;

	clock_t start2 = clock();
	mergeInsertionSort(dq);
	clock_t end2 = clock();
	double time2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000;

	std::cout << "Time to process a range of " << std::setw(3)
		<< dq.size() << " elements with std::deque  : "
		<< std::fixed << std::setprecision(5) << time2 << " us" << std::endl;

	std::cout << "\033[0m";
}