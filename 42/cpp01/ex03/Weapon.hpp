#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
	public:
		const std::string& getType(void) const;
		void	setType(const std::string& new_type);

		explicit Weapon(const std::string wep_name);
		~Weapon(void);

	private:
		std::string _type;
};

#endif