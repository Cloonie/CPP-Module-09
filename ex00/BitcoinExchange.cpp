#include "BitcoinExchange.hpp"

void removeWhitespaces(std::string& str) {
	for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
		if (std::isspace(*it)) {
			it = str.erase(it);
			--it;
		}
	}
}

bool checkDateFormat(std::string& str) {
	if (str.length() != 10)
		return false;
	if (str[4] != '-' || str[7] != '-')
		return false;
	for (int i = 0; i < 10; ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(str[i]))
			return false;
	}
	if (str[5] >= '1' && str[6] > '2')
		return false;
	if (str[8] >= '3' && str[9] > '1')
		return false;
	return true;
}

double getBitcoinPrice(const std::string& date, std::map<std::string, double> data) {
	std::map<std::string, double>::iterator it = data.find(date);
	if (it != data.end()) {
		return it->second;
	} else {
		it = data.lower_bound(date);
		if (it != data.begin()) {
			--it;
			return it->second;
		}
	}
	return -1.0;
}

BitcoinExchange::BitcoinExchange(char *file)
{
	std::ifstream datacsv;
	datacsv.open("./data.csv", std::ios::in);

	std::ifstream inputcsv;
	inputcsv.open(file, std::ios::in);

	if (!inputcsv.is_open())
	{
		std::cerr << "Error: '" << file << "' file not found" << std::endl;
		exit(1);
	}

	std::string	line;
	std::string	date;
	double		price;

	std::getline(datacsv, line); // Skip first line "date,exchange_rate"
	while (std::getline(datacsv, line))
	{
		std::istringstream stream(line);
		if (std::getline(stream, date, ',') && (stream >> price)
			&& checkDateFormat(date) == true)
			data.insert(std::make_pair(date, price));
		if (checkDateFormat(date) == false)
		{
			std::cerr << "Error: '" << data.size() << "' wrong format" << std::endl;
			exit(1);
		}
		// else
		// 	std::cerr << "Unable to get date and price: " << data.size() << std::endl;
		// std::cout << "Date: [" << date << "] Price: [" << price << "]" << std::endl;
	}

	std::getline(inputcsv, line); // Skip first line "date | value"
	while (std::getline(inputcsv, line))
	{
		std::istringstream stream(line);
		if (std::getline(stream, date, '|') && (stream >> price)
			&& price >= 0 && price <= 1000 && getBitcoinPrice(date, data) >= 0)
		{
			removeWhitespaces(date);
			if (checkDateFormat(date) == false)
				std::cout << "Error: bad input => " << date << std::endl;
			else
			{
				std::cout << date << " => " << price << " = "
				<< (price * getBitcoinPrice(date, data)) << std::endl;
			}
		}
		else
		{
			if (!stream)
				std::cout << "Error: bad input => " << date << std::endl;
			else if (price < 0)
				std::cout << "Error: not a positive number." << std::endl;
			else if (price > 1000)
				std::cout << "Error: too large a number." << std::endl;
			else
				std::cout << "Error: bad input => " << date << std::endl;
		}
	}
}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& ref)
{
	*this = ref;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& ref)
{
	data = ref.data;
	return (*this);
}
