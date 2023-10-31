#include "BitcoinExchange.hpp"
#include <fstream>

BitcoinExchange::BitcoinExchange()
{
	std::cout << "lolol" << std::endl;
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
