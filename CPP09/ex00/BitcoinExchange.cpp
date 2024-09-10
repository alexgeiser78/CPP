# include "BitcoinExchange.hpp"

// constructors

BitcoinExchange::BitcoinExchange()
{
    std::cout << "BitcoinExchange default constructor called" << std::endl;
	std::cout << "DB catching" << std::endl;
	dataBaseCatcher();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
    std::cout << "BitcoinExchange copy constructor called" << std::endl;
    if (this != &other)
        *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other)
{
    std::cout << "BitcoinExchange operator= called" << std::endl;
    if (this != &other)
    {
        _quotes = other._quotes;
    }
    return (*this);
}
//Specifically, the _quotes member of the current object (this) 
//is being assigned the value of the _quotes member from the other 
//object. 

BitcoinExchange::~BitcoinExchange()
{
    std::cout << "BitcoinExchange destructor called" << std::endl;
}

// Getters

std::map<std::string, float> const &BitcoinExchange::getQuotes() const
{
	return (_quotes);
}

// member functions

void BitcoinExchange::currencyExchange(char const *filename)
{
    std::ifstream file(filename); // creates an input file stream object and opens the file
    if (!file.is_open()) // member function from std::ifstream that returns true if the file is open
		throw CouldNotOpenFile();

    std::string line;
    std::getline(file, line); //for the first line containing date | value
    if (line != "date | value")
		throw InvalidColumnFormat();

    std::cout << "input file reading" << std::endl;
	std::cout << "computing..." << std::endl;
	std::cout << std::endl;

    while (std::getline(file, line)) //puts each line of the file into "line"
	{
        std::istringstream stringStream(line); //std::istringstream is a stream class to read from strings	
        std::cout << stringStream.str() << std::endl;

        std::string date;
		std::string value;      
        std::getline(stringStream, date, '|'); //store int "date" what is before |
		std::getline(stringStream, value, '|'); //or enconters an other | or the end of the line

		if (!date.empty())
			date = date.erase(date.length() -1); //delete the space at the end of the string "date"
        
        
		if (isValidDate(date) == false)
		{
			std::cout << "Error: wrong date => " << date << std::endl;
		}

		if(!value.empty())
			value = value.erase(0, 1); //delete the space at the beginning of the string "value"

        float priceValue; //convert value to float, (asked in the subject)
		priceValue = isValidPrice(value);
		
        if (priceValue != -1) //-1 is the "false" return value of _isValidPrice
			multiplyer(date, priceValue);
    }

    file.close();
}

void BitcoinExchange::dataBaseCatcher()
{
	std::ifstream file("data.csv");
	if (!file.is_open())
		throw CouldNotOpenFile();

	std::string line;
	std::getline(file, line);
	if (line != "date,exchange_rate")
            throw InvalidColumnFormat();
	
	while (std::getline(file, line))
	{
		std::istringstream stringStream(line);
		//std::cout << stringStream.str() << std::endl;

		std::string date;
		std::string price;   
        std::getline(stringStream, date, ',');
        std::getline(stringStream, price, ',');
		
		float priceValue;
		std::istringstream priceStream(price); //convert the string to a float
		if (!(priceStream >> priceValue)) //convert the string to a float and stores it in priceValue, ">>" extraction operator
				throw InvalidPriceFormat();
		_quotes[date] = priceValue; //store the date and the price in the map
	}	

	file.close();		
}

void BitcoinExchange::multiplyer(std::string const &date, float price)
{
    std::map<std::string, float>::iterator it = _quotes.find(date);

    if (it != _quotes.end()) // Exact match found
    {
        std::cout << "Exact match in _quotes map: " << it->first << " quote: " << it->second << std::endl;
        std::cout << date << " => " << price << " = " << price * it->second << std::endl;
    }
    else // No exact match
    {
        std::map<std::string, float>::iterator it2 = _quotes.lower_bound(date); // search for the first element that is not less than date (>= date)

        if (it2 == _quotes.begin()) // No earlier date in the DB 
        {
            std::cout << "No earlier date in the database, using the earliest available date: " << it2->first << " quote:" << it2->second << std::endl;
            std::cout << date << " => " << price << " = " << price * it2->second << std::endl;
        }
        else // Closest earlier date
        {
            if (it2->first != date)
                --it2; // go back one element
            std::cout << "No exact match for date: " << date << ", using closest earlier date: " << it2->first << " quote: " << it2->second << std::endl;
            std::cout << it2->first << " => " << price << " = " << price * it2->second << std::endl;
        }
    }
	std::cout << std::endl;
}

//isValidator functions

bool BitcoinExchange::isValidDate(std::string const &date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-') //check is 10 char and eparated by "-"
		return (false);
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (isdigit(date[i]) == 0) //check if the char is a digit
			return (false);
	}

	if (date[5] == '0' && date[6] == '0') 
		return (false);
	if ((date[5] == '1' && date[6] > '2') || date[5] > '1') //check there is no 13 month or more
		return (false); 

	if (date[8] == '0' && date[9] == '0')
		return (false);
	if ((date[8] == '3' && date[9] > '1') || date[8] > '3') //check there is no 32 days or more
		return (false);
	
	return (true);
}

double BitcoinExchange::isValidPrice(std::string const &value)
{
	float priceValue;
	std::istringstream priceStream(value);

	if (!(priceStream >> priceValue)) //try to convert the string to a float and stores it in priceValue
	{
		std::cout << "Error: bad input => " << priceValue << std::endl;
		std::cout << std::endl;
		return (-1);
	}

	if (priceValue < 0) //check if the value is positive
	{
		std::cout << "Error: not a positive number => " << priceValue << std::endl;
		std::cout << std::endl;
		return (-1);
	}
	else if (priceValue > 1000) //limit fixed in the subject
	{
		std::cout << "Error: too large number => " << priceValue << std::endl;
		std::cout << std::endl;
		return (-1);
	}
	
	return (priceValue);
}

