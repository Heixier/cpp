#include <cstring>
#include <iostream>
#include <stdexcept>

#include "colors.hpp"
#include "ShuntingYard.hpp"

static bool is_operator(int token)
{
	const char* operators = "+-/*()";
	for (int i = 0; operators[i]; i++)
	{
		if (token == operators[i])
			return (true);
	}
	return (false);
}

void ShuntingYard::generate()
{
	for (int i = 0; m_infix[i]; i++)
	{
		if (isdigit(m_infix[i]))
			push_digit(m_infix[i]);
		else if (is_operator(m_infix[i]))
			push_operator(m_infix[i]);
	}

	while (!m_operators.empty())
	{
		m_postfix.push_back(m_operators[m_operators.size() - 1]);
		m_operators.erase(m_operators.size() - 1);
	}

	std::cout << LIGHT_GREEN << "Operator stack: " << m_operators << '\n' << END;
	std::cout << ICE_BLUE << "Postfix stack: " << m_postfix << '\n' << END;
}

void ShuntingYard::push_operator(const char& c)
{
	if (c == '(')
		m_operators.push_back(c);
	if (c == ')')
	{
		if (m_operators.find_first_of('(')== std::string::npos)
			throw std::runtime_error("Unclosed brackets.");
		while (m_operators[m_operators.size() - 1] != '(')
		{
			m_postfix.push_back(m_operators[m_operators.size() - 1]);
			m_operators.erase(m_operators.size() - 1);
		}
		m_operators.erase(m_operators.size() - 1); // erase opening bracket
	}
	if (c == '*' || c == '/')
	{
		if (m_operators.find_last_of("*/") == std::string::npos)
			m_operators.push_back(c);
		else // same precedence found
		{
			m_postfix.push_back(m_operators[m_operators.size() - 1]);
			m_operators.erase(m_operators.size() - 1);
			m_operators.push_back(c);
		}
	}
	if (c == '+' || c == '-')
	{
		if (m_operators.find_last_of("+-*/") == std::string::npos)
			m_operators.push_back(c);
		else
		{
			while (!m_operators.empty() && m_operators[m_operators.size() - 1] != '(')
			{
				m_postfix.push_back(m_operators[m_operators.size() - 1]);
				m_operators.erase(m_operators.size() - 1);
			}
			m_operators.push_back(c);
		}
	}
}

void ShuntingYard::push_digit(const char& c)
{
	m_postfix.push_back(c);
}

static bool validate_infix(const char* infix)
{
	bool digit_flag = false;
	for (int i = 0; infix[i]; i++)
	{
		if (isdigit(infix[i]))
		{
			if (digit_flag)
				return (false);
			else
				digit_flag = true;
		}
		else if (!is_operator(infix[i]))
			return (false);
		else
			digit_flag = false;
		
	}
	return (true);
}

ShuntingYard::ShuntingYard(const char* infix): m_infix(infix)
{
	if (!validate_infix(m_infix))
		throw std::runtime_error("Invalid input.");
}

ShuntingYard::ShuntingYard() { }
ShuntingYard::ShuntingYard(const ShuntingYard& other): m_infix(other.m_infix), m_operators(other.m_operators), m_postfix(other.m_postfix) { }
ShuntingYard& ShuntingYard::operator= (const ShuntingYard& other)
{
	if (this != &other)
	{
		m_infix = other.m_infix;
		m_operators = other.m_operators;
		m_postfix = other.m_postfix;
	}
	return (*this);
}
ShuntingYard::~ShuntingYard() { }