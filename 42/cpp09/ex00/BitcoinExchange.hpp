#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
	public:
		void dump_database();
		void read_database();
		void reference_database();

		BitcoinExchange();
		BitcoinExchange(const std::string& filename);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator= (const BitcoinExchange& other);
		~BitcoinExchange();

	private:
		std::map<std::string, std::string> m_c;
		std::string m_filename;
};

#endif
