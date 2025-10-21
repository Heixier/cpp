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
void PmergeMe::v_swap_pairs(int level)
{

	int group_size = std::pow(2, level); // How many numbers in each half of the pair
	int pair_size = group_size * 2; // How big the pair is overall
	if (pair_size > m_elements)
	{
		std::cout << "Not enough elements to make a pair at level " << level << "! Needed: " << pair_size << " Provided: " << m_elements << '\n';
		return;
	}

	// std::cout << ICE_BLUE << "Swapping\n" << END;

	int pairs_created = m_elements / pair_size;

	std::cout << "Pair size: " << pair_size << " Group size: " << group_size << '\n';
	std::cout << "Pairs created: " << pairs_created << '\n';

	
	v_swap_pairs(level + 1);
}

void PmergeMe::handle_straggler(int argc, char **argv)
{
	if (m_elements % 2)
	{
		m_straggler = atoi(argv[argc - 1]);
		std::cout << LIGHT_GREEN << "Straggler caught: " << m_straggler << '\n' << END;
		--m_elements;
	}
}

PmergeMe::PmergeMe(int argc, char **argv): m_elements(0), m_deque_compares(0), m_vect_compares(0)
{
	if (argc < 2)
		throw std::runtime_error("Not enough arguments!");
	argc--;
	argv = &argv[1];
	if (!are_integers(argc, argv))
		throw std::runtime_error("Invalid digits!");

	m_vect.clear();
	m_v_main.clear();
	m_v_pend.clear();
	m_v_rem.clear();

	m_deque.clear();
	m_d_main.clear();
	m_d_pend.clear();
	m_d_rem.clear();

	m_elements = argc;

	handle_straggler(argc, argv);

	std::cout << "m_elements: " << m_elements << '\n';

	for (int i = 0; i < m_elements; i++)
	{
		m_deque.push_back(atoi(argv[i]));
		m_vect.push_back(atoi(argv[i]));
	}

	v_print(m_vect);

	v_swap_pairs(0);

	v_print(m_vect);

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

