#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	public:
		void	announce(void);
		void	set_name(std::string name);
		void	set_size(int size);
		int		get_size(void);

		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		
	private:
		std::string name;
		int	_horde_size;
};

#endif