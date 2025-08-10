#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character: public ICharacter
{
	public:
		void check_inventory(void) const;
		void check_sell_inventory(void) const;
		void sell(void);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		Character(void);
		Character(const std::string& name);
		Character(const Character& other);
		Character& operator= (const Character& other);
		~Character(void);
	
	private:
		AMateria* m_inventory[4];
		AMateria* m_stock[4];
		std::string m_name;
};

#endif