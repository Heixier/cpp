#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <vector>
#include <sys/time.h>
#include <iostream>
#include <stdexcept>
#include <algorithm>

#include "structs.hpp"

class PmergeMe
{
	public:
		PmergeMe(int argc, char **argv);
		~PmergeMe();

	private:

		void v_sort(std::vector<int> vect);
		void l_sort(std::list<int> vect);

		int v_swap_pairs(int level);
		int l_swap_pairs(int level);

		void v_insert(int level);
		int l_insert(int level);

		void v_flatten_into_m_vect(std::vector<std::vector<int> >& src);
		int l_flatten_into_m_list(std::list<std::list<int> >& src);

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
		
		template <typename Container, typename Container2>
		void c_print(Container2& vect2, const std::string& name) const
		{
			std::cout << name << ": \n";
			for (typename Container2::const_iterator iter2 = vect2.begin(); iter2 != vect2.end(); iter2++)
			{
				for (typename Container::const_iterator iter = iter2 -> begin(); iter != iter2 -> end(); iter++)
					std::cout << '[' << *iter << ']';
				std::cout << '\n';
			}
			std::cout << '\n';
		}

		template <typename T>
		T& lst_idx(std::list<T>& lst, int idx)
		{
			if (idx < 0)
				throw std::runtime_error("boi your index calculations got screwed up somewhere");
			typename std::list<T>::iterator it = lst.begin();
			std::advance(it, idx);
			return (*it);
		}

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
		int m_list_compares;
		int m_vect_compares;
		
		std::list<int> m_list;
		std::vector<int> m_vect;

		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe& operator= (const PmergeMe &other);
};

#endif