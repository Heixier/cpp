#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
	public:
		void dump_database();

		void exchange();

		BitcoinExchange();
		BitcoinExchange(const std::string& filename);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator= (const BitcoinExchange& other);
		~BitcoinExchange();

	private:
		void read_database();
		void reference_database(const std::string& date);

		std::map<std::string, double> m_c;
		std::string m_filename;
};

#endif
