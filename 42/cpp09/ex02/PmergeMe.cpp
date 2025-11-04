#include <sstream>
#include <stdexcept>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include "PmergeMe.hpp"

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

int PmergeMe::get_comparison_limit()
{
	if (!m_elements)
		return (0);
	int sum = 0;
	for (int i = 1; i <= m_elements; ++i)
		sum += std::ceil(std::log(3.0 * i / 4.0) / std::log(2.0));
	return (sum);
}


void PmergeMe::sort()
{
	struct timeval start;
	struct timeval end;

	// Vector
	c_print(m_vect, "Before sort");
	int comparisons = 0;
	int comparison_limit = get_comparison_limit();
	double time_taken;

	gettimeofday(&start, NULL);
	insert<std::vector<int>, std::vector<std::vector<int> >, std::vector<t_bounds> >(m_vect, swap_pairs<std::vector<int> >(m_vect, 0, comparisons), comparisons);
	gettimeofday(&end, NULL);

	c_print(m_vect, "After sort");
	if (!is_sorted<std::vector<int> >(m_vect))
		throw std::runtime_error("Not sorted!");
	if (comparisons > comparison_limit)
		throw std::runtime_error("Too many comparisons!");
	
	time_taken = ((end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0);
	std::cout << std::fixed << "Sorted " << m_elements << " elements in " << time_taken << "s with std::vector\n";
	comparisons = 0;
	gettimeofday(&start, NULL);
	insert<std::deque<int>, std::deque<std::deque<int> >, std::deque<t_bounds> >(m_deque, swap_pairs<std::deque<int> >(m_deque, 0, comparisons), comparisons);
	gettimeofday(&end, NULL);
	time_taken = ((end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0);
	std::cout << std::fixed << "Sorted " << m_elements << " elements in " << time_taken << "s with std::deque\n";

	if (!is_sorted<std::deque<int> >(m_deque))
		throw std::runtime_error("Not sorted!");
	if (comparisons > comparison_limit)
		throw std::runtime_error("Too many comparisons!");
	if (m_vect.size() != static_cast<size_t>(m_elements) || m_deque.size() != static_cast<size_t>(m_elements))
		throw std::runtime_error("Elements missing!");
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

	for (int i = 0; i < m_elements; i++)
	{
		m_deque.push_back(atoi(argv[i]));
		m_vect.push_back(atoi(argv[i]));
	}

	sort();
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

