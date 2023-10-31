#include "RPN.hpp"

RPN::RPN()
{

}

RPN::~RPN()
{

}

RPN::RPN(const RPN& ref)
{
	*this = ref;
}

RPN& RPN::operator=(const RPN& ref)
{
	(void)ref;
	return (*this);
}
