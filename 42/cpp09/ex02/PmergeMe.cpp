#include <stdexcept>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include "colors.hpp"
#include "PmergeMe.hpp"

std::vector<int> PmergeMe::v_generate_jacobsthal_sequence(int b_elements)
{
	if (b_elements >= 33)
		throw std::runtime_error("Too many numbers!");
	std::vector<int> jacobsthal_sequence;
	int current_idx = 0;
	int current_jacobsthal = 0;

	while (current_jacobsthal < b_elements)
	{
		current_jacobsthal = ((std::pow(2, current_idx) - std::pow(-1, current_idx)) / 3);
		// std::cout << "Current jacobsthal: " << current_jacobsthal << '\n';
		jacobsthal_sequence.push_back(current_jacobsthal);
		current_idx++;
	}
	// std::cout << "For b_elements: " << b_elements << '\n';
	// v_print(jacobsthal_sequence, "Jacobsthal");

	std::vector<int> output;
	output.clear();

	for (size_t i = 0; i + 1 < jacobsthal_sequence.size(); i++)
	{
		int num_of_elements_to_add = jacobsthal_sequence[i + 1] - jacobsthal_sequence[i];
		// std::cout << "Num of elements to add: " << num_of_elements_to_add << " for numbers between: " << jacobsthal_sequence[i + 1] << " and " << jacobsthal_sequence[i] << '\n';
		for (int j = 0; j < num_of_elements_to_add; j++)
		{
			int to_insert = jacobsthal_sequence[i + 1] - j;
			if (to_insert > 1 && to_insert <= b_elements)
			{
				// std::cout << "Inserting jacobsthal_sequence[i] - j = " << jacobsthal_sequence[i] << " - " << j << " = " << to_insert << '\n';
				output.push_back(to_insert);
			}
		}
	}
	return (output);
}

void PmergeMe::v_print(std::vector<int> vect, const std::string& name)
{
	std::cout << "Vector: " << name << ": ";
	for (std::vector<int>::iterator iter = vect.begin(); iter != vect.end(); iter++)
		std::cout << '[' << *iter << ']';
	std::cout << '\n';
}

void PmergeMe::v_print(std::vector<int> vect)
{
	std::cout << "Vector: ";
	for (std::vector<int>::iterator iter = vect.begin(); iter != vect.end(); iter++)
		std::cout << '[' << *iter << ']';
	std::cout << '\n';
}

void PmergeMe::v_print2(std::vector<std::vector<int> > vect2, const std::string& name)
{
	std::cout << "Vect2 " << name << ": \n";
	for (std::vector<std::vector<int > >::iterator iter2 = vect2.begin(); iter2 != vect2.end(); iter2++)
	{
		for (std::vector<int>::iterator iter = iter2 -> begin(); iter != iter2 -> end(); iter++)
			std::cout << '[' << *iter << ']';
		std::cout << '\n';
	}
	std::cout << '\n';
}

void PmergeMe::v_push_vect(std::vector<int> vect)
{
	for (std::vector<int>::iterator iter = vect.begin(); iter != vect.end(); iter++)
		m_vect.push_back(*iter);
}

void PmergeMe::v_push_vect(std::vector<std::vector<int > > vect2)
{
	for (std::vector<std::vector<int > >::iterator iter2 = vect2.begin(); iter2 != vect2.end(); iter2++)
	{
		for (std::vector<int>::iterator iter = iter2 -> begin(); iter != iter2 -> end(); iter++)
			m_vect.push_back(*iter);
	}
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
			std::cout << ICE_BLUE;
			v_print(buffer, "Copy of left group");
			std::cout << '\n' << END;
			buffer.clear();
		}
		v_print(m_vect, "m_vect");
	}
	
	return (v_swap_pairs(level + 1));
}


// Binary insert returns the index to put the value in
int PmergeMe::v_get_insert_pos(int to_insert, std::vector<std::vector<int> > v_main, std::vector<std::vector<int> > v_pend)
{
	int num_to_compare = v_pend[to_insert].back();
	int idx_upper_bound = to_insert + 2 - 1;
	int idx_lower_bound = 0;
	int size_of_search = idx_upper_bound - idx_lower_bound + 1;

	std::cout << "b" << to_insert + 2 << " (" << num_to_compare<< ") will be checked against the range of at idx " << idx_lower_bound << " (" << v_main[idx_lower_bound].back() << ") to a" << idx_upper_bound << " (" << v_main[idx_upper_bound].back() << ") search size: " << size_of_search << '\n';

	return (to_insert);
}

void PmergeMe::v_insert(int level)
{
	if (level < 0)
		return;
	std::vector<std::vector<int > > v_start;
	std::vector<std::vector<int > > v_main;
	std::vector<std::vector<int> > v_pend;
	std::vector<int> v_remainder;

	int group_size = std::pow(2, level); // How many numbers for each a/b section
	int groups = m_elements / group_size;

	v_start.clear();
	v_main.clear();
	v_pend.clear();
	v_remainder.clear();

	std::vector<int> buffer;

	std::cout << ORANGE << "Beginning insert for depth: " << level << "\nElements: " << m_elements << " Group size: " << group_size << " Groups: " << groups << '\n' << END;

	// Create v_start
	for (int group = 0; group < groups; group++)
	{
		for (int i = 0; i < group_size; i++)
			buffer.push_back(m_vect[i + (group * group_size)]);
		// v_print(buffer, "Insert buffer");
		// std::cout << '\n';
		v_start.push_back(buffer);
		// v_print2(v_start, "v_start");
		buffer.clear();
	}
 
	for (int i = group_size * groups; i < m_elements; i++)
		v_remainder.push_back(m_vect[i]);

	// Create v_main and v_pend
	for (int i = 0; i < groups; i++)
	{
		if (i % 2) // if a
		{
			std::cout << PURPLE << "a" << i / 2 + 1 << ": ";
			v_print(v_start[i]);
			std::cout << END;
			v_main.push_back(v_start[i]);
		}
		else // if b
		{
			if (i == 0) // b1
				v_main.push_back(v_start[i]);
			else
				v_pend.push_back(v_start[i]);
			std::cout << ICE_BLUE << "b" << i / 2 + 1 << ": ";
			v_print(v_start[i]);
			std::cout << END;
		}
	}

	std::cout << LIGHT_GREEN;
	v_print2(v_main, "v_main");
	std::cout << END;

	std::cout << ORANGE;
	v_print2(v_pend, "v_pend");
	std::cout << END;

	std::cout << YELLOW;
	v_print(v_remainder, "v_remainder");
	std::cout << END;

	// m_vect.clear();
	v_push_vect(v_main);
	// v_push_vect(v_pend); // TEMP; NOT LIKE THIS
	v_push_vect(v_remainder);
	// v_print(m_vect, "m_vect");

	std::vector<int> sequence = v_generate_jacobsthal_sequence(v_pend.size() + 1);
	v_print(sequence, "Full Jacobsthal sequence");

	// Time to find the search range

	// We know that main consists of b1, then all the as, so in order to know which a I am looking at, I can subtract 1 from the b sequence

	// Pend chain starts from b2 onwards, so that means b3 is index 3 - 1 for b1 and -1 for index = 1

	// Jacobsthal - 2 = index;

	for (std::vector<int>::iterator iter = sequence.begin(); iter != sequence.end(); iter++)
	{
		int idx_to_insert = v_get_insert_pos((*iter) - 2, v_main, v_pend); 
		idx_to_insert++;
	}

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

