#include <sstream>
#include <iostream>
#include <cstring>
#include <stdexcept>

#include "RPN.hpp"
#include "colors.hpp"

static bool valid_token(int token)
{
	if (isdigit(token))
		return (true);

	const char* operators = "+-/*";
	for (int i = 0; operators[i]; i++)
	{
		if (token == operators[i])
			return (true);
	}
	return (false);
}

static bool validate_input(const char* expr)
{
	if (!(strlen(expr) % 2))
		return (false);
	for (int i = 0; expr[i]; i++)
	{
		if (i % 2 == 0)
		{
			if (!valid_token(expr[i]))
				return (false);
		}
		else if (expr[i] != ' ')
			return (false);
	}
	return (true);
}

void RPN::calculate()
{
	while(!m_postfix.empty())
	{
		if (isdigit(m_postfix.top()))
		{
			m_result.push(m_postfix.top() - '0');
			m_postfix.pop();
		}
		else
		{
			if (m_result.size() < 2)
				throw std::runtime_error("Error"); // Invalid calculation
			
			char op = m_postfix.top();
			m_postfix.pop();

			int second = m_result.top();
			m_result.pop();
			int first = m_result.top();
			m_result.pop();

			long long overflow_check;
			int result;

			switch (op)
			{
				case '+':
					overflow_check = static_cast<long long>(first) + static_cast<long long>(second);
					result = first + second;
					if (result != overflow_check)
						throw std::runtime_error("Error"); // Overflow
					m_result.push(result);
					break;
				case '-':
					overflow_check = static_cast<long long>(first) - static_cast<long long>(second);
					result = first - second;
					if (result != overflow_check)
						throw std::runtime_error("Error"); // Overflow
					m_result.push(result);
					break;
				case '*':
					overflow_check = static_cast<long long>(first) * static_cast<long long>(second);
					result = first * second;
					if (result != overflow_check)
						throw std::runtime_error("Error"); // Overflow
					m_result.push(result);
					break;
				case '/':
					overflow_check = static_cast<long long>(first) / static_cast<long long>(second);
					result = first / second;
					if (result != overflow_check)
						throw std::runtime_error("Error"); // Overflow
					m_result.push(result);
					break;
				default:
					throw std::runtime_error("Error"); // Someone broke my code
			}
		}
	}
}

void RPN::evaluate()
{
	if (!m_postfix.empty() || m_result.size() != 1)
		throw (std::runtime_error("Error")); // Invalid calculation (not enough operators)
	std::cout << m_result.top() << '\n';
}

RPN::RPN(const char* postfix)
{
	if (!validate_input(postfix))
		throw (std::runtime_error("Error"));

	std::istringstream iss(postfix);
	std::string token;
	while (std::getline(iss, token, ' '))
		m_postfix.push(*token.c_str());
	m_postfix = reverse_stack(m_postfix);
}

RPN::RPN() { }
RPN::RPN(const RPN& other):m_postfix(other.m_postfix), m_result(other.m_result) { };
RPN& RPN::operator= (const RPN& other)
{
	if (this != &other)
	{
		m_postfix = other.m_postfix;
		m_result = other.m_result;
	}
	return (*this);
}
RPN::~RPN() { };