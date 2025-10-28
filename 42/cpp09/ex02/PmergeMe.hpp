#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <vector>

#include "structs.hpp"

class PmergeMe
{
	public:
		PmergeMe(int argc, char **argv);
		~PmergeMe();

	private:

		int v_swap_pairs(int level);
		void v_insert(int level);
		void v_push_vect(const std::vector<int>& vect);
		void v_push_vect(const std::vector<std::vector<int > >& vect2);

		void v_print(const std::vector<int>& vect) const;
		void v_print(const std::vector<int>& vect, const std::string &name) const;
		void v_print2(const std::vector<std::vector<int > >& vect2, const std::string& name) const;

		std::vector<int> v_generate_jacobsthal_sequence(int elements);
		void v_dynamic_binary_insert(std::vector<t_bounds> bounds, std::vector<std::vector<int> >& v_main, std::vector<std::vector<int> >& v_pend);
		std::vector<t_bounds> v_generate_bounds_pairing(const std::vector<int>& jacobsthal_sequence);

		int m_elements;
		int m_deque_compares;
		int m_vect_compares;
		
		std::deque<int> m_deque;

		std::vector<int> m_vect;

		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe& operator= (const PmergeMe &other);
};

#endif