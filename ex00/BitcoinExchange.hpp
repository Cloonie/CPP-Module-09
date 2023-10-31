#pragma once

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

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
