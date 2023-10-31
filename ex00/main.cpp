#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>

void removeWhitespaces(std::string& str) {
	for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
		if (std::isspace(*it)) {
			it = str.erase(it);
			--it;
		}
	}
}

// void checkDateFormat(std::string& str) {}

// void getLowerDate() {}

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

	// BitcoinExchange bc;

	std::map<std::string, double>	data;
	std::string	line;
	std::string	date;
	double		price;

	while (std::getline(datacsv, line))
	{
		std::istringstream stream(line);
		if (std::getline(stream, date, ',') && (stream >> price))
			data.insert(std::make_pair(date, price));
		// else
		// 	std::cerr << "Unable to get date and price: " << data.size() << std::endl;
		// std::cout << "Date: [" << date << "] Price: [" << price << "]" << std::endl;
	}

	std::getline(inputcsv, line); // Skip first line "date | value"
	while (std::getline(inputcsv, line))
	{
		std::istringstream stream(line);
		if (std::getline(stream, date, '|') && (stream >> price)
			&& price >= 0 && price <= 1000)
		{
			removeWhitespaces(date);
			std::cout << date << " => "
			<< price << " = " << (data.at("2011-01-04") * price)
			<< std::endl;
		}
		else
		{
			if (price < 0)
				std::cout << "Error: not a positive number." << std::endl;
			else if (price > 1000)
				std::cout << "Error: too large a number." << std::endl;
			else
				std::cout << "Error: " << std::endl;
		}
	}
	// std::cout << data.at("2022-03-25") << std::endl;
	// std::cout << data.size() << std::endl;
}