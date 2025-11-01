#include <sstream>
#include <stdexcept>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include "PmergeMe.hpp"
#include "structs.hpp"

static bool are_positive_integers(int argc, char **argv)
{
	int buffer = 0;

	std::istringstream iss;

	for (int i = 0; i < argc; i++)
	{
		iss.str(argv[i]);
		if (iss >> buffer && iss.eof() && buffer >= 0)
		{
			iss.clear();
			continue;
		}
		return (false);
	}
	return (true);
}

PmergeMe::PmergeMe(int argc, char **argv): m_elements(0), m_deque_compares(0), m_vect_compares(0)
{
	if (argc < 2)
		throw std::runtime_error("Not enough arguments!");
	argc--;
	argv = &argv[1];
	if (!are_positive_integers(argc, argv))
		throw std::runtime_error("Invalid digits!");

	m_vect_compares = m_deque_compares;

	m_vect.clear();
	m_deque.clear();
	m_elements = argc;

	std::cout << "m_elements: " << m_elements << '\n';

	for (int i = 0; i < m_elements; i++)
	{
		m_deque.push_back(atoi(argv[i]));
		m_vect.push_back(atoi(argv[i]));
	}

	sort<std::vector<int>, std::vector<std::vector<int> >, std::vector<t_bounds> >("std::vector", m_vect);
	sort<std::deque<int>, std::deque<std::deque<int> >, std::deque<t_bounds> >("std::deque", m_deque);
}

PmergeMe::PmergeMe(): m_elements(0), m_deque_compares(0), m_vect_compares(0)
{
	m_vect.clear();
	m_deque.clear();
}

PmergeMe::PmergeMe(const PmergeMe& other):
	m_elements(other.m_elements),
	m_deque_compares(other.m_deque_compares),
	m_vect_compares(other.m_deque_compares),
	m_deque(other.m_deque),
	m_vect(other.m_vect)
{ }

PmergeMe& PmergeMe::operator= (const PmergeMe& other)
{
	if (this != &other)
	{
		m_deque = other.m_deque;
		m_vect = other.m_vect;
	}
	return (*this);
}

PmergeMe::~PmergeMe() { }

