#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <vector>

class PmergeMe
{
	public:
		PmergeMe(int argc, char **argv);
		~PmergeMe();
	private:

		void v_swap_pairs(int level);
		void v_print(std::vector<int> vect);
		int max_pairs(int level);
		void handle_straggler(int argc, char **argv);

		bool m_straggler_caught;

		int m_straggler;
		int m_elements;
		int m_deque_compares;
		int m_vect_compares;
		
		std::deque<int> m_deque;
		std::deque<int> m_d_main;
		std::deque<int> m_d_pend;
		std::deque<int> m_d_rem;

		std::vector<int> m_vect;
		std::vector<int> m_v_main;
		std::vector<int> m_v_pend;
		std::vector<int> m_v_rem;

		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe& operator= (const PmergeMe &other);
};

#endif