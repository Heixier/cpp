#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	public:
		std::string ideas[100];

		void think(const std::string thought);
		void think(const std::string (&thoughts)[100]);
		const std::string& get_thought(int idx);
		void think_aloud(void) const;
	
		Brain(void);
		Brain(const Brain& other);
		Brain& operator= (const Brain& other);
		~Brain(void);

	private:
		std::string thought;
};

#endif