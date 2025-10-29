#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <vector>
#include <sys/time.h>
#include <iostream>
#include <stdexcept>

#include "structs.hpp"

class PmergeMe
{
	public:
		PmergeMe(int argc, char **argv);
		~PmergeMe();

	private:

		void v_sort(std::vector<int> vect);
		int v_swap_pairs(int level);
		void v_insert(int level);

		void v_push_flattened_vect(std::vector<std::vector<int> >& src);

		template <typename Container>
		Container generate_insertion_sequence(int pend_elements)
		{
			Container jacobsthal_sequence(0);

			jacobsthal_sequence.push_back(0);
			jacobsthal_sequence.push_back(1);
		
			int last = 1;
			int prev = 0;
			int next;
			while (last < pend_elements)
			{
				if (jacobsthal_sequence.size() > 32)
					throw std::runtime_error("Too many numbers!");
				next = last + 2 * prev;
				jacobsthal_sequence.push_back(next);
				prev = last;
				last = next;
			}

			Container output(0);
			for (size_t i = 0; i + 1 < jacobsthal_sequence.size(); i++)
			{
				int num_of_elements_to_add = jacobsthal_sequence[i + 1] - jacobsthal_sequence[i];
				for (int j = 0; j < num_of_elements_to_add; j++)
				{
					int to_insert = jacobsthal_sequence[i + 1] - j;
					if (to_insert > 1 && to_insert <= pend_elements)
						output.push_back(to_insert);
				}
			}
			return (output);
		}

		template <typename Container, typename PairContainer>
		PairContainer generate_bounds_pairing(const Container& jacobsthal_sequence)
		{
			PairContainer bounds(0);
			t_bounds buffer;

			for (typename Container::const_iterator iter = jacobsthal_sequence.begin(); iter != jacobsthal_sequence.end(); iter++)
			{
				buffer.b_element_idx = *iter - 2;
				buffer.exclusive_upper_bound_idx = *iter;
				bounds.push_back(buffer);
			}
			return (bounds);
		}

		void v_dynamic_binary_insert(std::vector<t_bounds> jacobsthal_pairings, std::vector<std::vector<int> >& main, std::vector<std::vector<int > > pend);

		template <typename Container>
		void c_print(const Container& c, const std::string& name) const
		{
			std::cout << name << ": ";
			for (typename Container::const_iterator iter = c.begin(); iter != c.end(); iter++)
				std::cout << '[' << *iter << ']';
			std::cout << '\n';
		}
		
		template <typename Container>
		void c_print(const Container& c) const
		{
			std::cout << "Container: ";
			for (typename Container::const_iterator iter = c.begin(); iter != c.end(); iter++)
				std::cout << '[' << *iter << ']';
			std::cout << '\n';
		}
		
		void v_print2(const std::vector<std::vector<int > >& vect2, const std::string& name) const;

		template <typename Container>
		bool is_sorted(Container c)
		{
			for (typename Container::iterator it = c.begin(); it != c.end(); it++)
			{
				if ((it + 1 != c.end() && *it > *(it + 1)))
					return (false);
			}
			return (true);
		}

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