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

void PmergeMe::v_push_flattened_vect(std::vector<std::vector<int> >& src)
{
	for (std::vector<std::vector<int> >::const_iterator iter2 = src.begin(); iter2 != src.end(); iter2++)
	{
		for (std::vector<int>::const_iterator iter = iter2 -> begin(); iter != iter2 -> end(); iter++)
			m_vect.push_back(*iter);
	}
}

void PmergeMe::v_sort(std::vector<int> vect)
{
	struct timeval start;
	struct timeval end;

	c_print(vect, "Before sort");
	gettimeofday(&start, NULL);

	int depth = v_swap_pairs(0);
	v_insert(depth);
	gettimeofday(&end, NULL);

	c_print(m_vect, "\nAfter sort");
	if (!is_sorted<std::vector<int> >(m_vect))
		std::cout << RED << "Not sorted!\n" << END;

	double time_taken_us = ((end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0);
	std::cout << "Sorted " << m_elements << " elements in " << time_taken_us << "s with std::vector " << " (" << m_vect_compares << " comparisons)\n";
}

// Idx starts from 0; recursion
int PmergeMe::v_swap_pairs(int level)
{
	int group_size = std::pow(2, level); // How many numbers in each half of the pair
	int pair_size = group_size * 2; // How big the pair is overall
	if (pair_size > m_elements)
		return (level);

	int pairs_created = m_elements / pair_size;

	std::vector<int> buffer;
	for (int i = 0; i < pairs_created; i++)
	{
		++m_vect_compares;
		int left_group_start_idx = (i * 2 * group_size);
		int right_group_start_idx = (i * 2 * group_size) + group_size;

		int left_group_end_idx = (i * 2 * group_size) + group_size - 1;
		int right_group_end_idx = (i * 2 * group_size) + (group_size * 2) - 1;

		if (m_vect[left_group_end_idx] > m_vect[right_group_end_idx])
		{
			for (int i = 0; i < group_size; i++) // Copy the left group
			{
				buffer.push_back(m_vect[i + left_group_start_idx]);
				m_vect[i + left_group_start_idx] = m_vect[i + right_group_start_idx];
				m_vect[i + right_group_start_idx] = buffer[i];
			}
			buffer.clear();
		}
	}
	return (v_swap_pairs(++level));
}

void PmergeMe::v_dynamic_binary_insert(std::vector<t_bounds> jacobsthal_pairings, std::vector<std::vector<int> >& main, std::vector<std::vector<int > > pend)
{
	for (std::vector<t_bounds>::iterator jacobsthal_iter = jacobsthal_pairings.begin(); jacobsthal_iter != jacobsthal_pairings.end(); jacobsthal_iter++)
	{
		int lower_bound_idx = 0;
		int upper_bound_idx = jacobsthal_iter -> exclusive_upper_bound_idx - 1;

		int to_insert = pend[jacobsthal_iter -> b_element_idx].back();
		while (lower_bound_idx <= upper_bound_idx)
		{
			++m_vect_compares;
			int to_compare_idx = lower_bound_idx + (upper_bound_idx - lower_bound_idx) / 2;
			if (to_insert <= main[to_compare_idx].back())
				upper_bound_idx = to_compare_idx - 1;
			else
				lower_bound_idx = to_compare_idx + 1;
		}

		int insertion_idx = lower_bound_idx;
		main.insert(main.begin() + insertion_idx, pend[jacobsthal_iter -> b_element_idx]);

		// Push every index above it up by one to account for the newly inserted element
		for (std::vector<t_bounds>::iterator iter = jacobsthal_iter; iter != jacobsthal_pairings.end(); iter++)
		{
			if (iter -> exclusive_upper_bound_idx >= insertion_idx)
				++iter -> exclusive_upper_bound_idx;
		}
	}
}

void PmergeMe::v_insert(int level)
{
	if (level < 0)
		return;
	std::vector<std::vector<int> > start(0);
	std::vector<std::vector<int> > main(0);
	std::vector<std::vector<int> > pend(0);
	std::vector<int> remainder(0);

	int group_size = std::pow(2, level); // How many numbers for each a/b section
	int groups = m_elements / group_size;
	std::vector<int> buffer(0);

	// Create v_start
	for (int group = 0; group < groups; group++)
	{
		for (int i = 0; i < group_size; i++)
			buffer.push_back(m_vect[i + (group * group_size)]);
		start.push_back(buffer);
		buffer.clear();
	}
	
	for (int i = group_size * groups; i < m_elements; i++)
		remainder.push_back(m_vect[i]);

	// Create v_main and v_pend
	for (int i = 0; i < groups; i++)
	{
		if (i % 2) // if a
			main.push_back(start[i]);
		else // if b
		{
			if (i == 0) // b1
				main.push_back(start[i]);
			else
				pend.push_back(start[i]);
		}
	}

	std::vector<int> sequence = generate_insertion_sequence<std::vector<int> >(pend.size() + 1);

	std::vector<t_bounds> pairings = generate_bounds_pairing<std::vector<int>, std::vector<t_bounds> >(sequence);
	v_dynamic_binary_insert(pairings, main, pend);

	m_vect.clear();
	v_push_flattened_vect(main);
	v_insert(--level);
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

	v_sort(m_vect);
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

