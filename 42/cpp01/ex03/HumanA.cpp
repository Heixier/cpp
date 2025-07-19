#include "HumanA.hpp"

void HumanA::attack(void) { std::cout << _name << " attacks with their " << _weapon.getType() << '\n'; }

HumanA::HumanA(const std::string name, const Weapon& weapon) :  _name(name), _weapon(weapon) { }
HumanA::~HumanA(void) { }