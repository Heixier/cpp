#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	public:
		void attack(void);

		explicit HumanA(const std::string name, const Weapon& weapon);
		~HumanA(void);
		
	private:
		std::string		_name;
		const Weapon&	_weapon;
};

#endif