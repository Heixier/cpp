#include <stdexcept>
#include <iostream>
#include <cstring>
#include <cstdlib>

#include "PmergeMe.hpp"

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

PmergeMe::PmergeMe(int argc, char **argv)
{
	if (argc < 2)
		throw std::runtime_error("Not enough arguments!");
	argc--;
	argv = &argv[1];
	if (!are_integers(argc, argv))
		throw std::runtime_error("Invalid digits!");
	m_list.clear();
	m_vect.clear();

	for (int i = 0; i < argc; i++)
	{
		m_list.push_back(atoi(argv[i]));
		m_vect.push_back(atoi(argv[i]));
	}

	for (std::list<int>::iterator iter = m_list.begin(); iter != m_list.end(); iter++)
		std::cout << "List: " << *iter << '\n';
	
	for (std::vector<int>::iterator iter = m_vect.begin(); iter != m_vect.end(); iter++)
		std::cout << "Vector: " << *iter << '\n';
}

PmergeMe::PmergeMe() { }
PmergeMe::PmergeMe(const PmergeMe& other): m_list(other.m_list), m_vect(other.m_vect) { }
PmergeMe& PmergeMe::operator= (const PmergeMe& other)
{
	if (this != &other)
	{
		m_list = other.m_list;
		m_vect = other.m_vect;
	}
	return (*this);
}

PmergeMe::~PmergeMe() { }