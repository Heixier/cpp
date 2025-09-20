#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>
#include <typeinfo>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		// void print_container_type() { std::cout << typeid(typename std::stack<T>::container_type).name() << '\n'; }
	
		iterator begin() { return (std::stack<T>::c.begin()); }
		iterator end() { return (std::stack<T>::c.end()); }

		const_iterator begin() const { return (std::stack<T>::c.begin()); }
		const_iterator end() const { return (std::stack<T>::c.end()); }

		MutantStack(): std::stack<T>() { }
		MutantStack(const MutantStack& other): std::stack<T>(other) { }

		MutantStack& operator= (const MutantStack& other)
		{
			if (this != &other)
				std::stack<T>::operator=(other);
			return (*this);
		}
		~MutantStack() { }
};

#endif