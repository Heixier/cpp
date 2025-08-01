#include "DiamondTrap.hpp"

void	DiamondTrap::whoAmI(void)
{
	if (m_hp <= 0)
	{
		std::cout << RED << "FAILED: " << BLUE << "DiamondTrap " << get_name() << " is dead!\n" << END;
		return;
	}
	std::cout << BLUE << "Name: " << std::right << std::setw(8) << get_name() << YELLOW << "\nClap name: " << std::right << std::setw(8) << ClapTrap::m_name<< END << std::endl;
}

void	DiamondTrap::guardGate(void)
{
	if (this -> get_health() <= 0)
	{
		std::cout << RED << "FAILED: " << BLUE << "DiamondTrap " << get_name() << " is dead!\n" << END;
		return ;
	}
	std::cout << BLUE << get_name() << " is now gatekeeping Serena, my love!\n" << END;
}

void	DiamondTrap::highFiveGuys(void)
{
	if (this -> get_health() <= 0)
	{
		std::cout << RED << "FAILED: " << BLUE << "DiamondTrap " << get_name() << " is dead!\n" << END;
		return ;
	}
	int	choice = rand() % 4;
	static const std::string choices[4] = { "Secret handshake!", "Up top!", "Gimme five!", "High five!" };

	if (m_energy)
	{
		m_energy--;
		std::cout << BLUE << get_name() << ": " << choices[choice] << END << std::endl;
		std::cout << BLUE << get_name() << END <<" has " << m_energy << " energy left!\n";
	}
	else
		std::cout << RED << "FAILED: " BLUE << "FragTrap " << get_name() << " is out of energy!\n" << END;

}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	if (m_hp > 0)
	{
		if (amount < m_hp)
		{
			m_hp -= amount;
			std::cout << BLUE << "DiamondTrap " << get_name() << " took " << amount << " damage!\n" << END;
			std::cout << BLUE << "Health left: " << GREEN << m_hp << END << '\n';
		}
		else
		{
			m_hp = 0;
			std::cout << BLUE << "Health left: " << RED << m_hp << END << '\n';
			std::cout << BLUE << "DiamondTrap " << get_name() << RED << " has died!\n" << END;
		}
	}
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	unsigned long long	result = static_cast<unsigned long long>(amount) + static_cast<unsigned long long>(m_hp);

	if (m_hp > 0)
	{
		if (m_energy)
			m_energy--;
		else
		{
			std::cout << RED << "FAILED: " << BLUE << "DiamondTrap " << get_name() << " is out of energy!\n" << END;
			return ;
		}
		if (result >= UINT_MAX)
			m_hp = UINT_MAX;
		else
			m_hp += amount;
		std::cout << BLUE << "DiamondTrap " << get_name() << " was repaired for " << GREEN << amount << " health!\n" << END;
		std::cout << BLUE << "Health: " << GREEN << m_hp << END << '\n';
		std::cout << BLUE << get_name() << END <<" has " << m_energy << " energy left!\n";
	}
	else
		std::cout << RED << "FAILED: " << BLUE << "DiamondTrap " << get_name() << " is dead!\n" << END;
}

const unsigned int&	DiamondTrap::get_attack(void) const { return (m_damage); }
const unsigned int&	DiamondTrap::get_health(void) const { return (m_hp); }
const unsigned int&	DiamondTrap::get_energy(void) const { return (m_energy); }
const std::string& DiamondTrap::get_name(void) const { return (m_name); }

DiamondTrap::DiamondTrap(void) : ClapTrap("Diamond_clap_name")
{
	m_name = "Diamond";
	m_hp = FragTrap::hp;
	m_energy = ScavTrap::energy;
	m_damage = FragTrap::damage;
	std::cout << BLUE << "DiamondTrap " << get_name() << " has spawned!\nHP: " << m_hp << "\nEnergy: " << m_energy << "\nDamage: " << m_damage << END << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name")
{
	m_name = name;
	m_hp = FragTrap::hp;
	m_energy = ScavTrap::energy;
	m_damage = FragTrap::damage;
	std::cout << BLUE << "DiamondTrap " << get_name() << " has spawned!\nHP: " << m_hp << "\nEnergy: " << m_energy << "\nDamage: " << m_damage << END << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	*this = other;
	std::cout << BLUE << "DiamondTrap " << other.m_name << " has been copied!" << END << std::endl;
}

DiamondTrap& DiamondTrap::operator= (const DiamondTrap& other)
{
	std::cout << BLUE << "DiamondTrap " << other.m_name << " has been copy assigned!" << END << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		m_name = other.m_name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void) { std::cout << BLUE << "DiamondTrap " << get_name() << " has been destroyed!\n" << END;  }
