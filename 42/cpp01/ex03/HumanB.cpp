#include "HumanB.hpp"

void HumanB::attack(void) { std::cout << _name << " attacks with their " << _weapon -> getType() << '\n'; }
void HumanB::setWeapon(Weapon *new_weapon) { _weapon = new_weapon; }

HumanB::HumanB(const std::string name) : _name(name) { }
HumanB::~HumanB(void) { }