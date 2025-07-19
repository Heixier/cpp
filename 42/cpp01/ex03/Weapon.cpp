#include "Weapon.hpp"

const std::string&	Weapon::getType(void) const { return _type; }

void	Weapon::setType(const std::string& new_type) { _type = new_type; }

Weapon::Weapon(const std::string weapon_name) : _type(weapon_name) { }
Weapon::~Weapon(void) { std::cout << _type << " has been destroyed\n"; }
