#include <stdexcept>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iomanip>

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

void PmergeMe::v_push_into_m_vect2(std::vector<std::vector<int> >& src)
{
	for (std::vector<std::vector<int> >::const_iterator iter2 = src.begin(); iter2 != src.end(); iter2++)
	{
		for (std::vector<int>::const_iterator iter = iter2 -> begin(); iter != iter2 -> end(); iter++)
			m_vect.push_back(*iter);
	}
}

void PmergeMe::l_push_into_m_list2(std::list<std::list<int> >& src)
{
	for (std::list<std::list<int> >::const_iterator iter2 = src.begin(); iter2 != src.end(); iter2++)
	{
		for (std::list<int>::const_iterator iter = iter2 -> begin(); iter != iter2 -> end(); iter++)
			m_list.push_back(*iter);
	}
}

void PmergeMe::l_push_into_m_list(std::list<int>& src)
{
	for (std::list<int>::const_iterator iter = src.begin(); iter != src.end(); iter++)
		m_list.push_back(*iter);
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
	std::cout << std::fixed << "Sorted " << m_elements << " elements in " << time_taken_us << "s with std::vector " << " (" << m_vect_compares << " comparisons)\n";
}

void PmergeMe::l_sort(std::list<int> lst)
{
	// struct timeval start;
	// struct timeval end;

	c_print(lst, "Before sort");
	// gettimeofday(&start, NULL);

	int depth = l_swap_pairs(0);
	l_insert(depth);
	// gettimeofday(&end, NULL);

	// c_print(m_list, "\nAfter sort");
	// if (!is_sorted<std::list<int> >(m_list))
	// 	std::cout << RED << "Not sorted!\n" << END;

	// double time_taken_us = ((end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0);
	// std::cout << std::fixed << "Sorted " << m_elements << " elements in " << time_taken_us << "s with std::list" << " (" << m_list_compares << " comparisons)\n";
}

// Idx starts from 0; recursion
int PmergeMe::v_swap_pairs(int level)
{
	int group_size = std::pow(2, level); // How many numbers in each half of the pair
	int pair_size = group_size * 2; // How big the pair is overall
	if (pair_size > m_elements)
	{
		std::cout << "Level: " << level << " Not enough to make next level! Needed: " << pair_size << " Provided: " << m_elements << " Stopping...\n";
		return (level);
	}

	int pairs_created = m_elements / pair_size;

	std::cout << "Pair size: " << pair_size << " Group size: " << group_size << '\n';
	std::cout << "Pairs created: " << pairs_created << '\n';

	std::vector<int> buffer;
	for (int i = 0; i < pairs_created; i++)
	{
		++m_vect_compares;
		int left_group_start_idx = (i * 2 * group_size);
		int right_group_start_idx = (i * 2 * group_size) + group_size;

		int left_group_end_idx = (i * 2 * group_size) + group_size - 1;
		int right_group_end_idx = (i * 2 * group_size) + (group_size * 2) - 1;

		std::cout << LIGHT_GREEN << "start_of_left_group: " << m_vect[left_group_start_idx] << " start_of_right_group: " << m_vect[right_group_start_idx] << '\n' << END;
		std::cout << YELLOW << "end_of_left_group: " << m_vect[left_group_end_idx] << " end_of_right_group: " << m_vect[right_group_end_idx] << '\n' << END;

		if (m_vect[left_group_end_idx] > m_vect[right_group_end_idx])
		{
			for (int i = 0; i < group_size; i++) // Copy the left group
			{
				buffer.push_back(m_vect[i + left_group_start_idx]);
				m_vect[i + left_group_start_idx] = m_vect[i + right_group_start_idx];
				m_vect[i + right_group_start_idx] = buffer[i];
			}
			std::cout << ICE_BLUE;
			c_print(buffer, "Copy of left group");
			std::cout << '\n' << END;
			buffer.clear();
		}
	}
	return (v_swap_pairs(++level));
}

int PmergeMe::l_swap_pairs(int level)
{
	int group_size = std::pow(2, level);
	int pair_size = group_size * 2;
	if (pair_size > m_elements)
	{
		std::cout << "Level: " << level << " Not enough to make next level! Needed: " << pair_size << " Provided: " << m_elements << " Stopping...\n";
		return (level);
	}

	// std::cout << ICE_BLUE << "Swapping\n" << END;
	int pairs_created = m_elements / pair_size;

	std::cout << "Pair size: " << pair_size << " Group size: " << group_size << '\n';
	std::cout << "Pairs created: " << pairs_created << '\n';

	std::list<int> buffer;
	for (int i = 0; i < pairs_created; i++)
	{
		++m_list_compares;
		int left_group_start_idx = (i * 2 * group_size);
		int right_group_start_idx = (i * 2 * group_size) + group_size;

		int left_group_end_idx = (i * 2 * group_size) + group_size - 1;
		int right_group_end_idx = (i * 2 * group_size) + (group_size * 2) - 1;

		std::cout << LIGHT_GREEN << "start_of_left_group: " << lst_idx(m_list, left_group_start_idx) << " start_of_right_group: " << lst_idx(m_list, right_group_start_idx) << '\n' << END;
		std::cout << YELLOW << "end_of_left_group: " << lst_idx(m_list, left_group_end_idx) << " end_of_right_group: " << lst_idx(m_list, right_group_end_idx) << '\n' << END;

		if (lst_idx(m_list, left_group_end_idx) > lst_idx(m_list, right_group_end_idx))
		{
			for (int i = 0; i < group_size; i++) // Copy the left group
			{
				buffer.push_back(lst_idx(m_list, i + left_group_start_idx));
				lst_idx(m_list, i + left_group_start_idx) = lst_idx(m_list, i + right_group_start_idx);
				lst_idx(m_list, i + right_group_start_idx) = lst_idx(buffer, i);
			}
			std::cout << ICE_BLUE;
			c_print(buffer, "Copy of left group");
			std::cout << '\n' << END;
			buffer.clear();
		}
		c_print(m_list, "m_list");
	}
	
	return (l_swap_pairs(++level));
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

void PmergeMe::l_dynamic_binary_insert(std::list<t_bounds> jacobsthal_pairings, std::list<std::list<int> >& main, std::list<std::list<int > > pend)
{
	for (std::list<t_bounds>::iterator jacobsthal_iter = jacobsthal_pairings.begin(); jacobsthal_iter != jacobsthal_pairings.end(); jacobsthal_iter++)
	{
		int lower_bound_idx = 0;
		int upper_bound_idx = jacobsthal_iter -> exclusive_upper_bound_idx - 1;

		int to_insert = lst_idx(pend, jacobsthal_iter -> b_element_idx).back();
		while (lower_bound_idx <= upper_bound_idx)
		{
			++m_list_compares;
			int to_compare_idx = lower_bound_idx + (upper_bound_idx - lower_bound_idx) / 2;
			if (to_insert <= lst_idx(main, to_compare_idx).back())
				upper_bound_idx = to_compare_idx - 1;
			else
				lower_bound_idx = to_compare_idx + 1;
		}

		int insertion_idx = lower_bound_idx;
		main.insert(lst_idx_it(main, insertion_idx), lst_idx(pend, jacobsthal_iter -> b_element_idx));

		// Push every index above it up by one to account for the newly inserted element
		for (std::list<t_bounds>::iterator iter = jacobsthal_iter; iter != jacobsthal_pairings.end(); iter++)
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

	std::cout << ORANGE << "Beginning insert for depth: " << level << "\nElements: " << m_elements << " Group size: " << group_size << " Groups: " << groups << '\n' << END;

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
		{
			std::cout << PURPLE << "a" << i / 2 + 1 << ": ";
			c_print(start[i], "");
			std::cout << END;
			main.push_back(start[i]);
		}
		else // if b
		{
			if (i == 0) // b1
				main.push_back(start[i]);
			else
				pend.push_back(start[i]);
			std::cout << ICE_BLUE << "b" << i / 2 + 1 << ": ";
			c_print(start[i], "");
			std::cout << END;
		}
	}


	std::cout << LIGHT_GREEN;
	c_print<std::vector<int>, std::vector<std::vector<int> > >(main, "v_main");
	std::cout << END;

	std::cout << ORANGE;
	c_print<std::vector<int>, std::vector<std::vector<int> > >(pend, "v_pend");
	std::cout << END;

	std::cout << YELLOW;
	c_print(remainder, "v_remainder");
	std::cout << END;

	std::vector<int> sequence = generate_insertion_sequence<std::vector<int> >(pend.size() + 1);

	std::vector<t_bounds> pairings = generate_bounds_pairing<std::vector<int>, std::vector<t_bounds> >(sequence);
	v_dynamic_binary_insert(pairings, main, pend);

	m_vect.clear();
	v_push_into_m_vect2(main);
	v_insert(--level);
}

void PmergeMe::l_insert(int level)
{
	if (level < 0)
		return;
	std::list<std::list<int> > start(0);
	std::list<std::list<int> > main(0);
	std::list<std::list<int> > pend(0);
	std::list<int> remainder(0);

	int group_size = std::pow(2, level); // How many numbers for each a/b section
	int groups = m_elements / group_size;
	std::list<int> buffer(0);

	std::cout << ORANGE << "Beginning insert for depth: " << level << "\nElements: " << m_elements << " Group size: " << group_size << " Groups: " << groups << '\n' << END;

	// Create l_start
	for (int group = 0; group < groups; group++)
	{
		for (int i = 0; i < group_size; i++)
			buffer.push_back(lst_idx(m_list, i + (group * group_size)));
		start.push_back(buffer);
		buffer.clear();
	}
	
	for (int i = group_size * groups; i < m_elements; i++)
		remainder.push_back(lst_idx(m_list, i));

	// Create v_main and v_pend
	for (int i = 0; i < groups; i++)
	{
		if (i % 2) // if a
		{
			std::cout << PURPLE << "a" << i / 2 + 1 << ": ";
			c_print(lst_idx(start, i), "");
			std::cout << END;
			main.push_back(lst_idx(start, i));
		}
		else // if b
		{
			if (i == 0) // b1
				main.push_back(lst_idx(start, i));
			else
				pend.push_back(lst_idx(start, i));
			std::cout << ICE_BLUE << "b" << i / 2 + 1 << ": ";
			c_print(lst_idx(start, i), "");
			std::cout << END;
		}
	}

	m_vect.clear();
	l_push_into_m_list2(main);
	l_push_into_m_list(remainder);

	std::cout << LIGHT_GREEN;
	c_print<std::list<int>, std::list<std::list<int> > >(main, "v_main");
	std::cout << END;

	std::cout << ORANGE;
	c_print<std::list<int>, std::list<std::list<int> > >(pend, "v_pend");
	std::cout << END;

	std::cout << YELLOW;
	c_print(remainder, "v_remainder");
	std::cout << END;

	std::list<int> sequence = generate_insertion_sequence<std::list<int> >(pend.size() + 1);

	std::list<t_bounds> pairings = generate_bounds_pairing<std::list<int>, std::list<t_bounds> >(sequence);
	l_dynamic_binary_insert(pairings, main, pend);

	m_list.clear();
	l_push_into_m_list2(main);
	l_insert(--level);
}

#include <unistd.h>
#include <fcntl.h>
#include <cstdio>

PmergeMe::PmergeMe(int argc, char **argv): m_elements(0), m_list_compares(0), m_vect_compares(0)
{
	if (argc < 2)
		throw std::runtime_error("Not enough arguments!");
	argc--;
	argv = &argv[1];
	if (!are_integers(argc, argv))
		throw std::runtime_error("Invalid digits!");

	m_vect_compares = m_list_compares;

	m_vect.clear();
	m_list.clear();
	m_elements = argc;

	std::cout << "m_elements: " << m_elements << '\n';

	for (int i = 0; i < m_elements; i++)
	{
		m_list.push_back(atoi(argv[i]));
		m_vect.push_back(atoi(argv[i]));
	}

	int fd = open("vect.txt", O_WRONLY | O_CREAT, 0777);
	if (fd == -1)
	{
		std::perror("open");
		throw std::runtime_error("file error");
	}
	int stdout = dup(STDOUT_FILENO);
	dup2(fd, STDOUT_FILENO);
	v_sort(m_vect);

	close(fd);

	fd = open("list.txt", O_WRONLY | O_CREAT, 0777);
	if (fd == -1)
	{
		std::perror("open");
		throw std::runtime_error("file error");
	}
	dup2(fd, STDOUT_FILENO);
	l_sort(m_list);
	close(fd);
	dup2(stdout, STDOUT_FILENO);
}

PmergeMe::PmergeMe(): m_elements(0), m_list_compares(0), m_vect_compares(0)
{
	m_vect.clear();
	m_list.clear();
}

PmergeMe::PmergeMe(const PmergeMe& other):
	m_elements(other.m_elements),
	m_list_compares(other.m_list_compares),
	m_vect_compares(other.m_list_compares),
	m_list(other.m_list),
	m_vect(other.m_vect)
{ }

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

