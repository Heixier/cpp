#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
	public:
		void dump_database();

		BitcoinExchange(const std::string& filename);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator= (const BitcoinExchange& other);
		~BitcoinExchange();

	private:
		BitcoinExchange();
		std::map<std::string, float> m_c;
		std::string m_filename;
};

#endif
