#include "RPN.hpp"

void	checkTokens(std::string tokens)
{
	for (int i = 0;)
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: ./RPN [\"Calculation\"]" << std::endl;
		return 1;
	}

	std::string	math = argv[1];
	std::cout << math << std::endl;
}