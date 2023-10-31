#pragma once

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
	public:
		BitcoinExchange(char *file);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& ref);
		BitcoinExchange& operator=(const BitcoinExchange& ref);

	private:
		std::map<std::string, double> data;
};
