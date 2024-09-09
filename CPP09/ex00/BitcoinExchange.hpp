#ifndef BICOINEXCHANGE_HPP
#define BICOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map> //std::map is a associative container that stores elements formed by a combination of a key value and a mapped value, following a specific order.
# include <fstream> //std::ifstream is a stream class to read from files
# include <sstream> //std::istringstream is a stream class to read from strings
# include <exception>

class BitcoinExchange
{
    private:
		std::map<std::string, float>	_quotes; //string is the key, double is the value, the key must be unique, _quotes is the map name storing the key-value pairs
        
        

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        //member functions
        void currencyExchange(char const *filename); //with std::string it doesn't work because it's c++11
        void multiplyer(std::string const &date, float price);
        
        //isValidator functions
        bool isValidDate(std::string const &date);
        double isValidPrice(std::string const &value);
        
        //exceptions

        class CouldNotOpenFile : public std::exception
		{
			public:
				virtual const char *what() const throw() //This function overrides the what() function from the std::exception class.
				{
					return ("Error: Could not open file");
				}
		};

		class InvalidColumnFormat : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Invalid column format. Expected 'date,exchange_rate'");
				}
		};

    
};





#endif