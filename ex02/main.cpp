#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	// argument error handling
	if (argc < 2)
	{
		std::cerr << "Error: ./PmergeMe [...]" << std::endl;
		return 1;
	}

	// PmergeMe Class
	PmergeMe object;
	object.pmergeme(argv);
}