#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
	public:
		void	attack(void);
		void	setWeapon(Weapon *new_weapon);
	
		HumanB(const std::string name);
		~HumanB(void);

	private:
		const std::string	_name;
		Weapon* 			_weapon;
};

#endif