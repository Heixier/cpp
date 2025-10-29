#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <vector>
#include <sys/time.h>

#include "structs.hpp"
#include "colors.hpp"

class PmergeMe
{
	public:
		PmergeMe(int argc, char **argv);
		~PmergeMe();

	private:
	
		template <typename Container, typename Container2, typename PairContainer>
		void sort(const std::string& container_name, Container& c)
		{
			struct timeval start;
			struct timeval end;

			c_print(c, "Before sort");
			int comparisons = 0;
			gettimeofday(&start, NULL);

			int depth = swap_pairs<std::vector<int> >(c, 0, comparisons);
			insert<Container, Container2, PairContainer>(c, depth, comparisons);
			gettimeofday(&end, NULL);

			c_print(m_vect, "\nAfter sort");
			if (!is_sorted<std::vector<int> >(m_vect))
				std::cout << RED << "Not sorted!\n" << END;

			double time_taken_us = ((end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0);
			std::cout << "Sorted " << m_elements << " elements in " << time_taken_us << "s with " << container_name << " (" << comparisons << " comparisons)\n";
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
			}
			return (swap_pairs(c, level + 1, comparisons));
		}

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

		template <typename Container2, typename PairContainer>
		void dynamic_binary_insert(PairContainer jacobsthal_pairings, Container2& main, Container2& pend, int& comparisons)
		{
			for (typename PairContainer::iterator jacobsthal_iter = jacobsthal_pairings.begin(); jacobsthal_iter != jacobsthal_pairings.end(); jacobsthal_iter++)
			{
				int lower_bound_idx = 0;
				int upper_bound_idx = jacobsthal_iter -> exclusive_upper_bound_idx - 1;

				int to_insert = pend[jacobsthal_iter -> b_element_idx].back();
				while (lower_bound_idx <= upper_bound_idx)
				{
					++comparisons;
					int to_compare_idx = lower_bound_idx + (upper_bound_idx - lower_bound_idx) / 2;
					if (to_insert <= main[to_compare_idx].back())
						upper_bound_idx = to_compare_idx - 1;
					else
						lower_bound_idx = to_compare_idx + 1;
				}

				int insertion_idx = lower_bound_idx;
				main.insert(main.begin() + insertion_idx, pend[jacobsthal_iter -> b_element_idx]);

				// Push every index above it up by one to account for the newly inserted element
				for (typename PairContainer::iterator iter = jacobsthal_iter; iter != jacobsthal_pairings.end(); iter++)
				{
					if (iter -> exclusive_upper_bound_idx >= insertion_idx)
						++iter -> exclusive_upper_bound_idx;
				}
			}
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
		
			Container sequence = generate_insertion_sequence<Container>(pend.size() + 1);
		
			PairContainer pairings = generate_bounds_pairing<Container, PairContainer>(sequence);
			dynamic_binary_insert<Container2, PairContainer>(pairings, main, pend, comparisons);
		
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