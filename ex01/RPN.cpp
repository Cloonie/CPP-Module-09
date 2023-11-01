#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN& ref) { *this = ref; }
RPN& RPN::operator=(const RPN& ref) { (void)ref; return (*this); }

void RPN::calculate(std::string argument)
{
	std::istringstream iss(argument);
	std::string token;
	while (iss >> token)
	{
		if (token.size() > 1)
		{
			std::cerr << "Error: Invalid token '" << token << "'" << std::endl;
			return;
		}
		else if (isdigit(token[0]) && token[0] >= '0' && token[0] <= '9')
			stack.push(atoi(token.c_str()));
		else if (token == "+" || token == "-"
			|| token == "*" || token == "/")
		{
			if (stack.size() < 2)
			{
				std::cerr << "Error: not enough operands" << std::endl;
				return;
			}
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();
			if (token == "+")
				stack.push(a + b);
			else if (token == "-")
				stack.push(a - b);
			else if (token == "*")
				stack.push(a * b);
			else if (token == "/")
			{
				if (b == 0) {
					std::cerr << "Error: Division by zero" << std::endl;
					return;
				}
				stack.push(a / b);
			}
		}
		else
		{
			std::cerr << "Error: Invalid token '" << token << "'" << std::endl;
			return;
		}
	}
	if (stack.size() == 1)
		std::cout << stack.top() << std::endl;
	else
	{
		std::cerr << "Error: Not enough operators" << std::endl;
		return;
	}
}