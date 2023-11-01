#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: ./RPN \"Calculation\"" << std::endl;
		return 1;
	}

	RPN rpn;
	rpn.calculate(argv[1]);
}