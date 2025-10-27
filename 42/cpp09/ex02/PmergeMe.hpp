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

		int v_swap_pairs(int level);
		void v_insert(int level);
		void v_push_vect(std::vector<int> vect);
		void v_push_vect(std::vector<std::vector<int > > vect2);

		void v_print(std::vector<int> vect);
		void v_print(std::vector<int> vect, const std::string &name);
		void v_print2(std::vector<std::vector<int > > vect2, const std::string& name);

		std::vector<int> v_generate_jacobsthal_sequence(int elements);
		int v_get_insert_pos(int to_insert, std::vector<std::vector<int> > v_main, std::vector<std::vector<int> > v_pend);

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