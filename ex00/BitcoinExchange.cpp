#include "BitcoinExchange.hpp"
#include <fstream>

BitcoinExchange::BitcoinExchange()
{
	std::cout << "~~~~~ BC Constructer ~~~~~" << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "~~~~~ BC Destructer ~~~~~" << std::endl;
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
