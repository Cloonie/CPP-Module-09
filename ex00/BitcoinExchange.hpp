#pragma once

#include <iostream>
#include <map>
#include <string>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& ref);
		BitcoinExchange& operator=(const BitcoinExchange& ref);

	private:
		std::map<std::string, double> data;
};
