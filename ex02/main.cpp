#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 1)
	{
		std::cerr << "Error: ./PmergeMe [...]" << std::endl;
		return 1;
	}
	
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
	std::cout << "vec it -> ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl
	<< "vec.front() -> " << vec.front() << std::endl
	<< "vec.back() -> " << vec.back() << std::endl
	<< "vec.size() -> " << vec.size() << std::endl;

	std::list<int> lst(vec.begin(), vec.end());
	// lst.reverse();
	std::cout << "lst it -> ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl
	<< "lst.front() -> " << lst.front() << std::endl
	<< "lst.back() -> " << lst.back() << std::endl
	<< "lst.size() -> " << lst.size() << std::endl;
}
