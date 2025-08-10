#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal
{
	public:
		void makeSound(void) const;
		void think_aloud(int amount) const;
		void think_about(const std::string& thought);
		void think_about(const int idx, const std::string& thought);
		const std::string& get_thought(const int idx) const;

		Dog(void);
		Dog(const Dog& other);
		Dog& operator= (const Dog& other);
		virtual ~Dog(void);

	private:
		Brain* brain;
		static const std::string m_sound;
};

#endif