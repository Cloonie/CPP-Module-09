#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: ./btc [file]" << std::endl;
		return 1;
	}
	BitcoinExchange bc(argv[1]);
}