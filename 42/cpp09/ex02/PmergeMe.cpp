#include <stdexcept>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include "colors.hpp"
#include "PmergeMe.hpp"

void PmergeMe::v_print(std::vector<int> vect)
{
	std::cout << "Vector: ";
	for (std::vector<int>::iterator iter = vect.begin(); iter != vect.end(); iter++)
		std::cout << '[' << *iter << ']';
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

	// std::cout << ICE_BLUE << "Swapping\n" << END;
	int pairs_created = m_elements / pair_size;

	std::cout << "Pair size: " << pair_size << " Group size: " << group_size << '\n';
	std::cout << "Pairs created: " << pairs_created << '\n';

	std::vector<int> buffer;
	for (int i = 0; i < pairs_created; i++)
	{
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
			std::cout << ICE_BLUE << "Copy of left group: ";
			v_print(buffer);
			std::cout << '\n' << END;
			buffer.clear();
		}
		v_print(m_vect);
	}
	
	return (v_swap_pairs(level + 1));
}

void PmergeMe::v_insert(int level)
{
	if (level < 0)
		return;
	std::vector<std::vector<int > > v_main;
	std::vector<std::vector<int> > v_pend;
	std::vector<int> v_remainder;

	int group_size = std::pow(2, level); // How many numbers for each a/b section

	// Need to create vector of vector<int> for each group, b1, a1, b2, etc.

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
	m_v_main.clear(); // might not need
	m_v_pend.clear(); // might not need
	m_v_rem.clear(); // might not need

	m_deque.clear();
	m_d_main.clear(); // might not need
	m_d_pend.clear(); // might not need
	m_d_rem.clear(); // might not need

	m_elements = argc;

	std::cout << "m_elements: " << m_elements << '\n';

	for (int i = 0; i < m_elements; i++)
	{
		m_deque.push_back(atoi(argv[i]));
		m_vect.push_back(atoi(argv[i]));
	}
	// Only doing vector for now; add deque later
	v_print(m_vect);

	int depth = v_swap_pairs(0);
	std::cout << "Final depth: " << depth << '\n';

	v_print(m_vect);

	v_insert(depth);

}

PmergeMe::PmergeMe(): m_elements(0), m_deque_compares(0), m_vect_compares(0)
{
	m_vect.clear();
	m_v_main.clear();
	m_v_pend.clear();
	m_v_rem.clear();

	m_deque.clear();
	m_d_main.clear();
	m_d_pend.clear();
	m_d_rem.clear();
}

PmergeMe::PmergeMe(const PmergeMe& other):
	m_elements(other.m_elements),
	m_deque_compares(other.m_deque_compares),
	m_vect_compares(other.m_deque_compares),
	m_deque(other.m_deque),
	m_d_main(other.m_d_main),
	m_d_pend(other.m_d_pend),
	m_d_rem(other.m_d_rem),
	m_vect(other.m_vect),
	m_v_main(other.m_v_main),
	m_v_pend(other.m_v_pend),
	m_v_rem(other.m_v_rem)
{ }

PmergeMe& PmergeMe::operator= (const PmergeMe& other)
{
	if (this != &other)
	{
		m_deque = other.m_deque;
		m_d_main = other.m_d_main;
		m_d_pend = other.m_d_pend;
		m_d_rem = other.m_d_rem;
		m_vect = other.m_vect;
		m_v_main = other.m_v_main;
		m_v_pend = other.m_v_pend;
		m_v_rem = other.m_v_rem;
	}
	return (*this);
}

PmergeMe::~PmergeMe() { }

