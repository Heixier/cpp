#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public AAnimal
{
	public:
		void makeSound(void) const;
		void think_aloud(int amount) const;
		void think_about(const std::string& thought);
		void think_about(const int idx, const std::string& thought);
		const std::string& get_thought(const int idx) const;
		
		Cat(void);
		Cat(const Cat& other);
		Cat& operator= (const Cat& other);
		virtual ~Cat(void);

	private:
		Brain* brain;
		static const std::string m_sound;
};

#endif