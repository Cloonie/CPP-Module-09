#include <iostream>
#include <fstream>
#include <string>

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		std::cout << "Error: ./btc [file]" << std::endl;
		return 1;
	}
	int fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		std::cout << "Error opening file" << std::endl;
		return 1;
	}
}