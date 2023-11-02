#include "PmergeMe.hpp"

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

int	main(int argc, char **argv)
{
	// argument error handling
	if (argc < 2)
	{
		std::cerr << "Error: ./PmergeMe [...]" << std::endl;
		return 1;
	}

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
			return 1;
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
		<< vec.size() << " elements with std::vector : " << time1 << " us"
		<< std::endl;

	clock_t start2 = clock();
	mergeInsertionSort(dq);
	clock_t end2 = clock();
	double time2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000;

	std::cout << "Time to process a range of " << std::setw(3)
		<< dq.size() << " elements with std::deque  : " << time2 << " us"
		<< std::endl;

	std::cout << "\033[0m";
}

	// std::cout << "vec it -> ";
	// for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	// 	std::cout << *it << " ";
	// std::cout << std::endl
	// << "vec.front() -> " << vec.front() << std::endl
	// << "vec.back() -> " << vec.back() << std::endl
	// << "vec.size() -> " << vec.size() << std::endl;

	// std::list<int> lst(vec.begin(), vec.end());
	// // lst.reverse();
	// std::cout << "lst it -> ";
	// for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
	// 	std::cout << *it << " ";
	// std::cout << std::endl
	// << "lst.front() -> " << lst.front() << std::endl
	// << "lst.back() -> " << lst.back() << std::endl
	// << "lst.size() -> " << lst.size() << std::endl;