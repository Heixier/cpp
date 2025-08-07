#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character: public ICharacter
{
	public:
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

		Character(void);
		Character(const std::string& name);
		Character(const Character& other);
		Character& operator= (const Character& other);
		~Character(void);
	
	private:
		AMateria* m_inventory[4];
		int m_hotbar;
		std::string m_name;
};

#endif