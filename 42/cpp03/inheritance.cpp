#include <iostream>

class Trex
{
	public:
		void	set_damage(int damage);
		void	take_damage(int damage);
		void	attack(Trex& target) const;
		void	status(void) const;

		Trex(void);
		Trex(const std::string name, int damage, int health);
		Trex(const Trex& copy);
		Trex& operator= (const Trex& copy);
		~Trex(void);

	protected:
		std::string m_name;
		int			m_damage;
		int			m_health;
};

void	Trex::set_damage(int damage)
{
	m_damage = damage;
}

void	Trex::take_damage(int damage)
{
	if (m_health > 0)
	{
		m_health -= damage;
		std::cout << m_name << " took " << damage << " damage!\n";
		if (m_health <= 0)
			std::cout << m_name << " has died!\n";
	}
}

void	Trex::attack(Trex& target) const
{
	if (m_health <= 0)
		return ;
	std::cout << m_name << " attacks " << target.m_name << " with " << m_damage << " damage\n";
	target.take_damage(m_damage);
	target.status();
}

void	Trex::status(void) const
{
	std::cout << m_name << " has " << m_health << " health left and " << m_damage << " damage\n";
}

Trex::Trex(void) : m_name("Steve"), m_damage(25), m_health(100) { }
Trex::Trex(const std::string name, int damage, int health) : m_name(name), m_damage(damage), m_health(health) { }
Trex::Trex(const Trex& copy) : m_name(copy.m_name), m_damage(copy.m_damage), m_health(copy.m_health) { }
Trex& Trex::operator= (const Trex& copy)
{
	if (this == &copy)
		return (*this);
	m_name = copy.m_name;
	m_damage = copy.m_damage;
	m_health = copy.m_health;		
	return (*this);
}

Trex::~Trex(void) { }

class Cub: public Trex
{
	public:
		Cub(void);
		Cub(std::string name, int damage, int health);
		Cub(const Cub& copy);
		Cub& operator= (const Cub& copy);
		~Cub(void);
};

Cub::Cub(void) : Trex() { }
Cub::Cub(const std::string name, int damage, int health) : Trex(name, damage, health) { }
Cub::Cub(const Cub& copy) : Trex(copy) { }
Cub& Cub::operator= (const Cub& copy)
{
	if (this != &copy)
	{
		Trex::operator=(copy);
	}
	return (*this);
}
Cub::~Cub(void) { }

int main(void)
{
	Trex	a;
	Trex	b("Ryner", 50, 100);
	Trex&	c (a);
	Cub		d("Kiki", 10, 50);

	c.set_damage(25);
	a.status();
	
	std::cout << "Begin fight\n";

	b.attack(a);
	d.attack(c);
	c.attack(b);
	a.attack(b);
	b.attack(c);
}
