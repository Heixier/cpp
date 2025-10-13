#include <stdexcept>
#include <iostream>
#include <cstring>
#include <cstdlib>

#include "colors.hpp"
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

// Idx starts from 0
void PmergeMe::swap_vector_pair(int pair_idx, int pair_size)
{
	int buffer = 0;
	int left_idx = pair_idx + pair_size * 2; // wrong
	int right_idx = left_idx + pair_size;

	std::cout << "Attempting to swap idx " << pair_idx << " of pair_size " << pair_size << " with idx + pair_size = " << pair_idx + pair_size << '\n';

	++m_vect_compares;
	if (m_vect[left_idx] <= m_vect[right_idx])
		return;

	for (int i = pair_idx; i < pair_size; i++)
	{
		buffer = m_vect[i];
		m_vect[i] = m_vect[i + pair_size];
		m_vect[i + pair_size] = buffer;
	}
}

// Starts from level 1
int PmergeMe::max_pairs(int level)
{
	int pair_size = level * 2;
	
	int num_pairs = m_elements / pair_size;

	std::cout << "Max pairs for level " << level << ": " << num_pairs << '\n';

	return (num_pairs);
}

PmergeMe::PmergeMe(int argc, char **argv): m_elements(0), m_list_compares(0), m_vect_compares(0)
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

	m_elements = m_list.size();

	// for (std::list<int>::iterator iter = m_list.begin(); iter != m_list.end(); iter++)
	// 	std::cout << "List: " << *iter << '\n';
	
	for (std::vector<int>::iterator iter = m_vect.begin(); iter != m_vect.end(); iter++)
		std::cout << "Vector: " << *iter << '\n';

	int level = 1;
	int pairs = max_pairs(level);

	for (int i = 0; i < pairs; i++)
		swap_vector_pair(i, level * 2);

	std::cout << ICE_BLUE << "Swapping\n" << END;

	for (std::vector<int>::iterator iter = m_vect.begin(); iter != m_vect.end(); iter++)
		std::cout << "Vector: " << *iter << '\n';

}

PmergeMe::PmergeMe(): m_elements(0), m_list_compares(0), m_vect_compares(0)
{
	m_vect.empty();
	m_list.empty();
}

PmergeMe::PmergeMe(const PmergeMe& other): m_elements(other.m_elements), m_list_compares(other.m_list_compares), m_vect_compares(other.m_list_compares), m_list(other.m_list), m_vect(other.m_vect) { }
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