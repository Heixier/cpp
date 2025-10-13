#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <vector>

class PmergeMe
{
	public:
		PmergeMe(int argc, char **argv);
		~PmergeMe();
	private:

		void swap_vector_pair(int pair_idx, int pair_size);
		int max_pairs(int level);

		int m_elements;
		int m_list_compares;
		int m_vect_compares;
		
		std::list<int> m_list;
		std::vector<int> m_vect;

		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe& operator= (const PmergeMe &other);
};

#endif