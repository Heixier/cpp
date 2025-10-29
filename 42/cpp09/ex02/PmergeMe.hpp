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
	
		template <typename Container, typename Container2, typename PairContainer>
		int sort(Container& c)
		{
			int comparisons = 0;
			int depth = swap_pairs<std::vector<int> >(c, 0, comparisons);
			insert<Container, Container2, PairContainer>(c, depth, comparisons);
			return (comparisons);
		}

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
				c_print(c, "m_vect");
			}
			return (swap_pairs(c, level + 1, comparisons));
		}

		template <typename Container, typename Container2, typename PairContainer>
		void insert(Container& c, int level, int& comparisons)
		{
			if (level < 0)
				return;
			Container2 start(0);
			Container2 main(0);
			Container2 pend(0);
			Container remainder(0);
		
			int group_size = std::pow(2, level); // How many numbers for each a/b section
			int groups = m_elements / group_size;
			Container buffer(0);
		
			// Create v_start
			for (int group = 0; group < groups; group++)
			{
				for (int i = 0; i < group_size; i++)
					buffer.push_back(c[i + (group * group_size)]);
				start.push_back(buffer);
				buffer.clear();
			}
		 
			for (int i = group_size * groups; i < m_elements; i++)
				remainder.push_back(c[i]);
		
			// Create v_main and v_pend
			for (int i = 0; i < groups; i++)
			{
				if (i % 2) // if a
					main.push_back(start[i]);
				else // if b
				{
					if (i == 0) // b1
						main.push_back(start[i]);
					else
						pend.push_back(start[i]);
				}
			}
		
			Container sequence = v_generate_jacobsthal_sequence(pend.size() + 1);
		
			PairContainer pairings = v_generate_bounds_pairing(sequence);
			v_dynamic_binary_insert(pairings, main, pend, comparisons);
		
			c.clear();
			push_to_flattened_container<Container, Container2>(main, c);
			insert<Container, Container2, PairContainer>(c, --level, comparisons);
		}

		template <typename Container, typename Container2>
		void push_to_flattened_container(const Container2& src, Container& dest)
		{
			for (typename Container2::const_iterator iter2 = src.begin(); iter2 != src.end(); iter2++)
			{
				for (typename Container::const_iterator iter = iter2 -> begin(); iter != iter2 -> end(); iter++)
					dest.push_back(*iter);
			}
		}

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

		std::vector<int> v_generate_jacobsthal_sequence(int elements);
		void v_dynamic_binary_insert(std::vector<t_bounds> jacobsthal_pairings, std::vector<std::vector<int> >& v_main, std::vector<std::vector<int> >& v_pend, int& comparisons);
		std::vector<t_bounds> v_generate_bounds_pairing(const std::vector<int>& jacobsthal_sequence);

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