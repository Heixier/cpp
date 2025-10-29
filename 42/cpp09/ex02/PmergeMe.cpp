#include <stdexcept>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include "colors.hpp"
#include "PmergeMe.hpp"
#include "structs.hpp"

std::vector<int> PmergeMe::v_generate_jacobsthal_sequence(int b_element_idxs)
{
	if (b_element_idxs >= 33)
		throw std::runtime_error("Too many numbers!");
	std::vector<int> jacobsthal_sequence;
	int current_idx = 0;
	int current_jacobsthal = 0;

	while (current_jacobsthal < b_element_idxs)
	{
		current_jacobsthal = ((std::pow(2, current_idx) - std::pow(-1, current_idx)) / 3);
		// std::cout << "Current jacobsthal: " << current_jacobsthal << '\n';
		jacobsthal_sequence.push_back(current_jacobsthal);
		current_idx++;
	}
	// std::cout << "For b_element_idxs: " << b_element_idxs << '\n';
	// c_print(jacobsthal_sequence, "Jacobsthal");

	std::vector<int> output;
	output.clear();

	for (size_t i = 0; i + 1 < jacobsthal_sequence.size(); i++)
	{
		int num_of_elements_to_add = jacobsthal_sequence[i + 1] - jacobsthal_sequence[i];
		// std::cout << "Num of elements to add: " << num_of_elements_to_add << " for numbers between: " << jacobsthal_sequence[i + 1] << " and " << jacobsthal_sequence[i] << '\n';
		for (int j = 0; j < num_of_elements_to_add; j++)
		{
			int to_insert = jacobsthal_sequence[i + 1] - j;
			if (to_insert > 1 && to_insert <= b_element_idxs)
			{
				// std::cout << "Inserting jacobsthal_sequence[i] - j = " << jacobsthal_sequence[i] << " - " << j << " = " << to_insert << '\n';
				output.push_back(to_insert);
			}
		}
	}
	return (output);
}

void PmergeMe::v_print2(const std::vector<std::vector<int> >& vect2, const std::string& name) const
{
	std::cout << "Vect2 " << name << ": \n";
	for (std::vector<std::vector<int > >::const_iterator iter2 = vect2.begin(); iter2 != vect2.end(); iter2++)
	{
		for (std::vector<int>::const_iterator iter = iter2 -> begin(); iter != iter2 -> end(); iter++)
			std::cout << '[' << *iter << ']';
		std::cout << '\n';
	}
	std::cout << '\n';
}

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

void PmergeMe::v_dynamic_binary_insert(std::vector<t_bounds> jacobsthal_pairings, std::vector<std::vector<int > >& v_main, std::vector<std::vector<int> >& v_pend, int& comparisons)
{
	for (std::vector<t_bounds>::iterator jacobsthal_iter = jacobsthal_pairings.begin(); jacobsthal_iter != jacobsthal_pairings.end(); jacobsthal_iter++)
		std::cout << "BEFORE: b_element_idx: " << jacobsthal_iter -> b_element_idx << " upper_bound: " << jacobsthal_iter -> exclusive_upper_bound_idx << '\n';

	for (std::vector<t_bounds>::iterator jacobsthal_iter = jacobsthal_pairings.begin(); jacobsthal_iter != jacobsthal_pairings.end(); jacobsthal_iter++)
	{
		int lower_bound_idx = 0;
		int upper_bound_idx = jacobsthal_iter -> exclusive_upper_bound_idx - 1;

		int to_insert = v_pend[jacobsthal_iter -> b_element_idx].back();
		while (lower_bound_idx <= upper_bound_idx)
		{
			++comparisons;
			int to_compare_idx = lower_bound_idx + (upper_bound_idx - lower_bound_idx) / 2;
			std::cout << ORANGE << "For value: " << to_insert << " at index " << jacobsthal_iter -> b_element_idx << " comparing from lower bound " << v_main[lower_bound_idx].back() << " at index " << lower_bound_idx << " to upper bound: " << v_main[upper_bound_idx].back() << " at index " << upper_bound_idx << '\n' << END;

			if (to_insert <= v_main[to_compare_idx].back())
				upper_bound_idx = to_compare_idx - 1;
			else
				lower_bound_idx = to_compare_idx + 1;
		}

		int insertion_idx = lower_bound_idx;
		std::cout << ICE_BLUE << "Inserting " << v_pend[jacobsthal_iter -> b_element_idx].back() << " of index " << jacobsthal_iter -> b_element_idx << " into index " << lower_bound_idx << " of main\n" << END;
		v_main.insert(v_main.begin() + insertion_idx, v_pend[jacobsthal_iter -> b_element_idx]);

		for (std::vector<t_bounds>::iterator iter = jacobsthal_iter; iter != jacobsthal_pairings.end(); iter++)
		{
			if (iter -> exclusive_upper_bound_idx >= insertion_idx)
			{
				std::cout << "For element: " << iter -> b_element_idx << " upper bound of idx: " << iter -> exclusive_upper_bound_idx << " is more than insertion idx of " << insertion_idx << ". Incrementing upper bound to " << iter -> exclusive_upper_bound_idx + 1 << '\n';
				++iter -> exclusive_upper_bound_idx;
			}
		}
		std::cout << "jacobsthal_iter -> b_element_idx: " << jacobsthal_iter -> b_element_idx << " jacobsthal_iter -> exclusive_upper_bound_idx: " << jacobsthal_iter -> exclusive_upper_bound_idx << '\n';
	}
	for (std::vector<t_bounds>::iterator jacobsthal_iter = jacobsthal_pairings.begin(); jacobsthal_iter != jacobsthal_pairings.end(); jacobsthal_iter++)
		std::cout << "RESULT: b_element_idx: " << jacobsthal_iter -> b_element_idx << " upper_bound: " << jacobsthal_iter -> exclusive_upper_bound_idx << '\n';
}

std::vector<t_bounds> PmergeMe::v_generate_bounds_pairing(const std::vector<int>& jacobsthal_sequence)
{
	std::vector<t_bounds> bounds(0);
	t_bounds buffer;

	for (std::vector<int>::const_iterator iter = jacobsthal_sequence.begin(); iter != jacobsthal_sequence.end(); iter++)
	{
		buffer.b_element_idx = *iter - 2;
		buffer.exclusive_upper_bound_idx = *iter;
		bounds.push_back(buffer);
	}
	return (bounds);
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

