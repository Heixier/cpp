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
	
		// Idx starts from 0; recursion
		template <typename Container>
		int swap_pairs(Container& c, int level, int& comparisons)
		{
			int group_size = std::pow(2, level); // How many numbers in each half of the pair
			int pair_size = group_size * 2; // How big the pair is overall
			if (pair_size > m_elements)
				return (level);

			int pairs_created = m_elements / pair_size;

			Container buffer;
			for (int i = 0; i < pairs_created; i++)
			{
				++comparisons;
				int left_group_start_idx = (i * 2 * group_size);
				int right_group_start_idx = (i * 2 * group_size) + group_size;

				int left_group_end_idx = (i * 2 * group_size) + group_size - 1;
				int right_group_end_idx = (i * 2 * group_size) + (group_size * 2) - 1;

				if (c[left_group_end_idx] > c[right_group_end_idx])
				{
					for (int i = 0; i < group_size; i++) // Copy the left group
					{
						buffer.push_back(c[i + left_group_start_idx]);
						c[i + left_group_start_idx] = c[i + right_group_start_idx];
						c[i + right_group_start_idx] = buffer[i];
					}
					buffer.clear();
				}
				v_print(c, "m_vect");
			}
			return (swap_pairs(c, level + 1, comparisons));
		}
		void v_insert(int level, int& comparisons);
		void v_push_vect(const std::vector<int>& vect);
		void v_push_vect(const std::vector<std::vector<int > >& vect2);

		void v_print(const std::vector<int>& vect) const;
		void v_print(const std::vector<int>& vect, const std::string &name) const;
		void v_print2(const std::vector<std::vector<int > >& vect2, const std::string& name) const;

		std::vector<int> v_generate_jacobsthal_sequence(int elements);
		void v_dynamic_binary_insert(std::vector<t_bounds> jacobsthal_pairings, std::vector<std::vector<int> >& v_main, std::vector<std::vector<int> >& v_pend, int& comparisons);
		std::vector<t_bounds> v_generate_bounds_pairing(const std::vector<int>& jacobsthal_sequence);

		template <typename Container, typename Container2, typename PairContainer>
		int sort(Container& c)
		{
			int comparisons = 0;
			int depth = swap_pairs<std::vector<int> >(c, 0, comparisons);
			v_insert(depth, comparisons);
			return (comparisons);
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
		int m_deque_compares;
		int m_vect_compares;
		
		std::deque<int> m_deque;

		std::vector<int> m_vect;

		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe& operator= (const PmergeMe &other);
};

#endif