#include <iostream>
#include <string>
#include "Contact.hpp"

Contact::Contact(void)
{
	this -> _first_name.clear();
	this -> _last_name.clear();
	this -> _nick_name.clear();
	this -> _phone_number.clear();
	this -> _secret.clear();
}

Contact::Contact(std::string first_name, std::string last_name, std::string nick_name, std::string phone_number, std::string secret) :
_first_name(first_name), _last_name(last_name), _nick_name(nick_name), _phone_number(phone_number), _secret(secret) { }

std::string Contact::get_first_name(void)
{
	return (this -> _first_name);
}

std::string Contact::get_last_name(void)
{
	return (this -> _last_name);
}

std::string Contact::get_nick_name(void)
{
	return (this -> _nick_name);
}

std::string Contact::get_phone_number(void)
{
	return (this -> _phone_number);
}

std::string Contact::get_secret(void)
{
	return (this -> _secret);
}

Contact::~Contact(void) { }
