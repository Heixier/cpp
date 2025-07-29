#include <iostream>

class Human
{
	public:
		Human(const std::string name);
		~Human(void);

	protected:
		const std::string _name;
};

Human::Human(std::string name) : _name(name) { std::cout << _name << " was born!\n"; }
Human::~Human(void) { std::cout << _name << " has died!\n"; }

class Warrior: public Human
{
	public:
		void	battlecry(void);
		Warrior(const std::string name);
	

};

Warrior::Warrior(const std::string name) : Human(name) { std::cout << _name << " has become a warrior\n"; }

void	Warrior::battlecry(void) { std::cout << "Rawr\n"; }

int main(void)
{
	Human a("John");
	Warrior b("Steven");

	b.battlecry();
}
