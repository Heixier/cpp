#ifndef ShuntingYard_HPP
#define ShuntingYard_HPP

#include <string>

class ShuntingYard
{
	public:
		void generate();
		
		ShuntingYard(const char* infix);
		~ShuntingYard();

	private:
		void push_operator(const char& c);
		void push_digit(const char& c);

		const char* m_infix;
		std::string m_operators;
		std::string m_postfix;

		ShuntingYard();
		ShuntingYard(const ShuntingYard& other);
		ShuntingYard& operator= (const ShuntingYard& other);
};

#endif