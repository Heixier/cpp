#include "FragTrap.hpp"
#include <cstdlib>

void	FragTrap::highFiveGuys(void)
{
	if (this -> get_health() <= 0)
	{
		std::cout << RED << "FAILED: " << ORANGE << "Fragtrap " << m_name << " is dead!\n" << END;
		return ;
	}
	int	choice = rand() % 4;
	static const std::string choices[4] = { "Secret handshake!", "Up top!", "Gimme five!", "High five!" };

	if (m_energy)
	{
		m_energy--;
		std::cout << ORANGE << m_name << ": " << choices[choice] << END << std::endl;
		std::cout << ORANGE << m_name << END <<" has " << m_energy << " energy left!\n";
	}
	else
		std::cout << RED << "FAILED: " ORANGE << "FragTrap " << m_name << " is out of energy!\n" << END;

}

void	FragTrap::attack(const std::string& target)
{
	if (m_hp <= 0)
	{
		std::cout << RED << "FAILED: " << ORANGE << "FragTrap " << m_name << " is dead!\n" << END;
		return;
	}
	if (m_energy)
	{
		std::cout << ORANGE << "FragTrap " << m_name << " shoots blindly at " << target << " for " << m_damage << " damage!\n" << END;
		m_energy--;
		std::cout << ORANGE << m_name << END <<" has " << m_energy << " energy left!\n";
	}
	else
		std::cout << RED << "FAILED: " ORANGE << "FragTrap " << m_name << " is out of energy!\n" << END;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (m_hp > 0)
	{
		if (amount < m_hp)
		{
			m_hp -= amount;
			std::cout << ORANGE << "FragTrap " << m_name << " took " << amount << " damage!\n" << END;
			std::cout << ORANGE << "Health left: " << GREEN << m_hp << END << '\n';
		}
		else
		{
			m_hp = 0;
			std::cout << ORANGE << "Health left: " << RED << m_hp << END << '\n';
			std::cout << ORANGE << "FragTrap " << m_name << RED << " has died!\n" << END;
		}
	}
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (m_hp > 0)
	{
		if (m_energy)
			m_energy--;
		else
		{
			std::cout << RED << "FAILED: " << ORANGE << "FragTrap " << m_name << " is out of energy!\n" << END;
			return ;
		}
		m_hp += amount;
		std::cout << ORANGE << "FragTrap " << m_name << " was repaired for " << GREEN << amount << " health!\n" << END;
		std::cout << ORANGE << "Health: " << GREEN << m_hp << END << '\n';
		std::cout << ORANGE << m_name << END <<" has " << m_energy << " energy left!\n";
	}
	else
		std::cout << RED << "FAILED: " << ORANGE << "FragTrap " << m_name << " is dead!\n" << END;
}

const unsigned int&	FragTrap::get_attack(void) const { return (m_damage); }
const unsigned int&	FragTrap::get_health(void) const { return (m_hp); }

FragTrap::FragTrap(void) : ClapTrap()
{
	m_hp = 100;
	m_energy = 100;
	m_damage = 30;
	std::cout << ORANGE << "FragTrap " << m_name << " has been spawned!\nHP: " << m_hp << "\nEnergy: " << m_energy << "\nDamage: " << m_damage << END << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	m_hp = 100;
	m_energy = 100;
	m_damage = 30;
	std::cout << ORANGE << "FragTrap " << m_name << " has been spawned!\nHP: " << m_hp << "\nEnergy: " << m_energy << "\nDamage: " << m_damage << END << std::endl;
}

FragTrap::FragTrap(const FragTrap& fragtrap) : ClapTrap(fragtrap) { }

FragTrap& FragTrap::operator= (const FragTrap& fragtrap)
{
	if (this != &fragtrap)
		ClapTrap::operator=(fragtrap);
	return (*this);
}

FragTrap::~FragTrap(void) { std::cout << ORANGE << "FragTrap " << m_name << " has been destroyed!\n" << END;  }