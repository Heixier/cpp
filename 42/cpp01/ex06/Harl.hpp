#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
	public:
		void		complain(std::string level) const;

		Harl(void);
		~Harl(void);

	private:
		void	debug(void) const;
		void	info(void) const;
		void	warning(void) const;
		void	error(void) const;

};

#endif
