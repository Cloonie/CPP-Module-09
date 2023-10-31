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
	std::ifstream datacsv;
	datacsv.open("./data.csv", std::ios::in);
	std::fstream inputcsv;
	inputcsv.open(argv[1], std::ios::in | std::ios::out);
	if (!inputcsv.is_open())
	{
		std::cerr << "Error: '" << argv[1] << "' file not found" << std::endl;
		return 1;
	}

	BitcoinExchange bc;
	std::map<std::string, double>	data;
	std::string	line;
	std::string	date;
	double		price;

	while (std::getline(datacsv, line))
	{
		std::istringstream stream(line);
		if (stream.fail())
			std::cerr << "Error during std::istringstream" << std::endl;
		if (std::getline(stream, date, ',') && (stream >> price))
			data.insert(std::make_pair(date, price));
		// else
		// 	std::cerr << "Unable to get date and price: " << data.size() << std::endl;
		// std::cout << "Date: [" << date << "] Price: [" << price << "]" << std::endl;
	}
	std::cout << data.at("2022-03-25") << std::endl;
	std::cout << data.size() << std::endl;
	std::cout << "date | value" << std::endl;
}