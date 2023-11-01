#pragma once

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <cstdlib>

class RPN
{
	public:
		RPN();
		~RPN();
		RPN(const RPN& ref);
		RPN& operator=(const RPN& ref);

		void calculate(std::string argument);
	private:
		std::stack<int> stack;
};