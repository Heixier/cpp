#include "FragTrap.hpp"
#include <cstdlib>

void	FragTrap::highFiveGuys(void)
{
	if (this -> get_health() <= 0)
	{
		std::cout << RED << "FAILED: " << ORANGE << "FragTrap " << get_name() << " is dead!\n" << END;
		return ;
	}
	int	choice = rand() % 4;
	static const std::string choices[4] = { "Secret handshake!", "Up top!", "Gimme five!", "High five!" };

	if (m_energy)
	{
		m_energy--;
		std::cout << ORANGE << get_name() << ": " << choices[choice] << END << std::endl;
		std::cout << ORANGE << get_name() << END <<" has " << m_energy << " energy left!\n";
	}
	else
		std::cout << RED << "FAILED: " ORANGE << "FragTrap " << get_name() << " is out of energy!\n" << END;

}

void	FragTrap::attack(const std::string& target)
{
	if (m_hp <= 0)
	{
		std::cout << RED << "FAILED: " << ORANGE << "FragTrap " << get_name() << " is dead!\n" << END;
		return;
	}
	if (m_energy)
	{
		std::cout << ORANGE << "FragTrap " << get_name() << " fires shots at " << target << " for " << m_damage << " damage!\n" << END;
		m_energy--;
		std::cout << ORANGE << get_name() << END <<" has " << m_energy << " energy left!\n";
	}
	else
		std::cout << RED << "FAILED: " ORANGE << "FragTrap " << get_name() << " is out of energy!\n" << END;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (m_hp > 0)
	{
		if (amount < m_hp)
		{
			m_hp -= amount;
			std::cout << ORANGE << "FragTrap " << get_name() << " took " << amount << " damage!\n" << END;
			std::cout << ORANGE << "Health left: " << GREEN << m_hp << END << '\n';
		}
		else
		{
			m_hp = 0;
			std::cout << ORANGE << "Health left: " << RED << m_hp << END << '\n';
			std::cout << ORANGE << "FragTrap " << get_name() << RED << " has died!\n" << END;
		}
	}
}

void	FragTrap::beRepaired(unsigned int amount)
{
	unsigned long long	result = static_cast<unsigned long long>(amount) + static_cast<unsigned long long>(m_hp);

	if (m_hp > 0)
	{
		if (m_energy)
			m_energy--;
		else
		{
			std::cout << RED << "FAILED: " << ORANGE << "FragTrap " << get_name() << " is out of energy!\n" << END;
			return ;
		}
		if (result >= UINT_MAX)
			m_hp = UINT_MAX;
		else
			m_hp += amount;
		std::cout << ORANGE << "FragTrap " << get_name() << " was repaired for " << GREEN << amount << " health!\n" << END;
		std::cout << ORANGE << "Health: " << GREEN << m_hp << END << '\n';
		std::cout << ORANGE << get_name() << END <<" has " << m_energy << " energy left!\n";
	}
	else
		std::cout << RED << "FAILED: " << ORANGE << "FragTrap " << get_name() << " is dead!\n" << END;
}

FragTrap::FragTrap(void) : ClapTrap()
{
	m_hp = hp;
	m_energy = energy;
	m_damage = damage;
	std::cout << ORANGE << "FragTrap " << get_name() << " has spawned!\nHP: " << m_hp << "\nEnergy: " << m_energy << "\nDamage: " << m_damage << END << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	m_hp = hp;
	m_energy = energy;
	m_damage = damage;
	std::cout << ORANGE << "FragTrap " << get_name() << " has spawned!\nHP: " << m_hp << "\nEnergy: " << m_energy << "\nDamage: " << m_damage << END << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) { std::cout << ORANGE << "FragTrap " << other.m_name << " has been copied!" << END << std::endl; }

FragTrap& FragTrap::operator= (const FragTrap& other)
{
	std::cout << ORANGE << "FragTrap " << other.m_name << " has been copy assigned!" << END << std::endl;
	if (this != &other)
	{
		m_name = other.m_name;
		m_hp = other.m_hp;
		m_energy = other.m_energy;
		m_damage = other.m_damage;
	}
	return (*this);
}

FragTrap::~FragTrap(void) { std::cout << ORANGE << "FragTrap " << get_name() << " has been destroyed!\n" << END;  }