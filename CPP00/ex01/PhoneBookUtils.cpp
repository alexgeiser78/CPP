#include "PhoneBook.hpp"

std::string	add_spaces(int n)
{
	std::string	str;

	while (n--)
		str.append(" "); //append n spaces to the string till 10 char
	return (str);
}


std::string set_width(std::string str, unsigned long width)  //width of 10 max
{
    if (str.length() > width)
    {
        str.resize(width);
        str[width - 1] = '.';
    }
    return (str);
}

int	search_flag(Contact users[8])
{
    std::string str;
    int i;
    char c;

    i = 0;
    c = '1';
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    while (i < 8)
    {
        if (users[i].get_firstname() != "")
        {
            str = c;
			str = set_width(str, 10);
			std::cout << "|" << add_spaces(10 - str.length()) << str;
			str = set_width(users[c - 1  - '0'].get_firstname(), 10);
			std::cout << "|" << add_spaces(10 - str.length()) << str;
			str = set_width(users[c - 1 - '0'].get_lastname(), 10);
			std::cout << "|" << add_spaces(10 - str.length()) << str;
			str = set_width(users[c - 1 - '0'].get_nickname(), 10);
			std::cout << "|" << add_spaces(10 - str.length()) << str;
			std::cout << "|" << std::endl;
        }
        i++;
        c++;
    }
    return (i);
}