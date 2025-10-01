#ifndef RPN_HPP
#define RPN_HPP

#include <stack>

// Display error and overflow accordingly; use just ints

class RPN
{
	public:
		void calculate();
		void evaluate();
		template <typename T>
		std::stack<T> reverse_stack(std::stack<T>& input)
		{
			std::stack<T> reversed;
			while (!input.empty())
			{
				reversed.push(input.top());
				input.pop();
			}
			return (reversed);
		}

		RPN(const char* postfix);
		~RPN();

	private:
		std::stack<char>m_postfix;
		std::stack<int>m_result;

		RPN();
		RPN(const RPN& other);
		RPN& operator= (const RPN& other);
};

#endif
