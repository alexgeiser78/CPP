# include "BitcoinExchange.hpp"

// constructors

BitcoinExchange::BitcoinExchange()
{
    std::cout << "BitcoinExchange default constructor called" << std::endl;
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

    std::cout << "input file:" << std::endl;
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

void BitcoinExchange::multiplyer(std::string const &date, float price)
{
	std::cout << "-multiplyer-" << std::endl;  
    
    std::map<std::string, float>::iterator it = _quotes.find(date); //find the date in the map
	 
    if (it != _quotes.end()) //if the date is found in the "_quotes" map
		{
        std::cout << "exact date found in _quotes map: " << it->first << std::endl;
        std::cout << date << " | " << price << " | " << price * it->second << std::endl; //it->first = key, it->second = value
        }
    else //if the date is not found
	{
        std::map<std::string, float>::iterator it2 = _quotes.lower_bound(date); // Lower bound returns an iterator pointing to the first element not less than 'date'
        
        // Check if it2 is equal to _quotes.end(), which means no element is greater or equal to date
        if (it2 == _quotes.end())
        {
            // No valid date found (all dates are before 'date')
            std::cout << "No equal date found in _quotes map for: " << date << std::endl;
        }
        else if (it2 == _quotes.begin()) // Check if it2 is at the beginning
        {
            // If 'it2' points to the beginning, all entries are after 'date'
            std::cout << date << " | " << price << " | " << price * it2->second << std::endl;
        }
        else
        {
            // Move the iterator to the previous element
            it2--;
            std::cout << date << " | " << price << " | " << price * it2->second << std::endl;
        }
    }
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
		return (-1);
	}

	if (priceValue < 0) //check if the value is positive
	{
		std::cout << "Error: not a positive number => " << priceValue << std::endl;
		return (-1);
	}
	else if (priceValue > 1000) //limit fixed in the subject
	{
		std::cout << "Error: too large number => " << priceValue << std::endl;
		return (-1);
	}
	
	return (priceValue);
}

