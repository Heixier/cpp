#include <stdexcept>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include "colors.hpp"
#include "PmergeMe.hpp"
#include "structs.hpp"

static bool are_integers(int argc, char **argv)
{
	for (int i = 0; i < argc; i++)
	{
		int element = 0;
		while (argv[i][element])
		{
			if (!std::isdigit(argv[i][element]) || std::strlen(argv[i]) > 11 || atoll(argv[i]) != atoi(argv[i]))
				return (false);
			element++;
		}
	}
	return (true);
}

PmergeMe::PmergeMe(int argc, char **argv): m_elements(0), m_deque_compares(0), m_vect_compares(0)
{
	if (argc < 2)
		throw std::runtime_error("Not enough arguments!");
	argc--;
	argv = &argv[1];
	if (!are_integers(argc, argv))
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

	int compares = sort<std::vector<int>, std::vector<std::vector<int> >, std::vector<t_bounds> >(m_vect);
	c_print(m_vect, "Final");
	if (!is_sorted<std::vector<int> >(m_vect))
		std::cout << RED << "Not sorted!\n" << END;
	else
		std::cout << LIGHT_GREEN << "Sorted!\n" << END;
	std::cout << "compares: " << compares << '\n';
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

