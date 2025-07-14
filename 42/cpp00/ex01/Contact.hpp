#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact {
	public:
		std::string	get_first_name(void);
		std::string get_last_name(void);
		std::string get_nick_name(void);
		std::string get_phone_number(void);
		std::string get_secret(void);

		Contact(void);
		Contact(std::string first_name, std::string last_name, std::string nick_name, std::string phone_number, std::string secret);
		~Contact(void);

	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nick_name;
		std::string _phone_number;
		std::string _secret;
};

#endif